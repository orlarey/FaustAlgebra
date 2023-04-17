#pragma once

#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>

#include "symbol.hh"

// A faust algebra is the set of primitive operations available in Faust on signals for example
template <typename T>
class FaustAlgebra
{
   public:
    using unfunc   = T (FaustAlgebra::*)(const T&);
    using binfunc  = T (FaustAlgebra::*)(const T&, const T&);
    using trifunc  = T (FaustAlgebra::*)(const T&, const T&, const T&);
    using quadfunc = T (FaustAlgebra::*)(const T&, const T&, const T&, const T&);
    using quinfunc = T (FaustAlgebra::*)(const T&, const T&, const T&, const T&, const T&);

    std::map<Sym, unfunc>   fUnFuncs;
    std::map<Sym, binfunc>  fBinFuncs;
    std::map<Sym, trifunc>  fTriFuncs;
    std::map<Sym, quadfunc> fQuadFuncs;
    std::map<Sym, quinfunc> fQuinFuncs;

    // Injections of external values
    virtual T nil()                       = 0;
    virtual T num(int x)                  = 0;
    virtual T num(double x)               = 0;
    virtual T label(const std::string& s) = 0;

    virtual T FixPointUpdate(const T& x, const T& y) = 0;  // used when searching fix point

    // User interface elements
    virtual T Button(const T& name)                                                           = 0;
    virtual T Checkbox(const T& name)                                                         = 0;
    virtual T VSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step)  = 0;
    virtual T HSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step)  = 0;
    virtual T NumEntry(const T& name, const T& init, const T& lo, const T& hi, const T& step) = 0;

    // Operations
    virtual T Abs(const T& x)               = 0;
    virtual T Add(const T& x, const T& y)   = 0;
    virtual T Sub(const T& x, const T& y)   = 0;
    virtual T Mul(const T& x, const T& y)   = 0;
    virtual T Div(const T& x, const T& y)   = 0;
    virtual T Inv(const T& x)               = 0;
    virtual T Neg(const T& x)               = 0;
    virtual T Mod(const T& x, const T& y)   = 0;
    virtual T Acos(const T& x)              = 0;
    virtual T Acosh(const T& x)             = 0;
    virtual T And(const T& x, const T& y)   = 0;
    virtual T Asin(const T& x)              = 0;
    virtual T Asinh(const T& x)             = 0;
    virtual T Atan(const T& x)              = 0;
    virtual T Atan2(const T& x, const T& y) = 0;
    virtual T Atanh(const T& x)             = 0;
    virtual T Ceil(const T& x)              = 0;
    virtual T Cos(const T& x)               = 0;
    virtual T Cosh(const T& x)              = 0;
    virtual T Delay(const T& x, const T& y) = 0;
    virtual T Eq(const T& x, const T& y)    = 0;
    virtual T Exp(const T& x)               = 0;
    virtual T FloatCast(const T& x)         = 0;
    virtual T Floor(const T& x)             = 0;
    virtual T Ge(const T& x, const T& y)    = 0;
    virtual T Gt(const T& x, const T& y)    = 0;
    virtual T IntCast(const T& x)           = 0;
    virtual T Le(const T& x, const T& y)    = 0;
    virtual T Log(const T& x)               = 0;
    virtual T Log10(const T& x)             = 0;
    virtual T Lsh(const T& x, const T& y)   = 0;
    virtual T Lt(const T& x, const T& y)    = 0;
    virtual T Max(const T& x, const T& y)   = 0;
    virtual T Mem(const T& x)               = 0;
    virtual T Min(const T& x, const T& y)   = 0;
    virtual T Ne(const T& x, const T& y)    = 0;
    virtual T Not(const T& x)               = 0;
    virtual T Or(const T& x, const T& y)    = 0;
    virtual T Pow(const T& x, const T& y)   = 0;
    virtual T Remainder(const T& x)         = 0;
    virtual T Rint(const T& x)              = 0;
    virtual T Rsh(const T& x, const T& y)   = 0;
    virtual T Sin(const T& x)               = 0;
    virtual T Sinh(const T& x)              = 0;
    virtual T Sqrt(const T& x)              = 0;
    virtual T Tan(const T& x)               = 0;
    virtual T Tanh(const T& x)              = 0;
    virtual T Xor(const T& x, const T& y)   = 0;

    //--------------------------------------------------------------------------------
    // Calling the various operations according to the opcode
    // and the number of arguments
    //--------------------------------------------------------------------------------

    // call unary opcode
    [[nodiscard]] T operator()(Sym n, const T& a)
    {
        auto p = fUnFuncs.find(n);
        if (p == fUnFuncs.end()) {
            std::cerr << "Unknown unary opcode " << n << std::endl;
            exit(-1);
        }
        return std::invoke(p->second, this, a);
    }

    // call binary opcode
    [[nodiscard]] T operator()(Sym n, const T& a, const T& b)
    {
        auto p = fBinFuncs.find(n);
        if (p == fBinFuncs.end()) {
            std::cerr << "Unknown binary opcode " << n << std::endl;
            exit(-1);
        }
        return std::invoke(p->second, this, a, b);
    }

    // call ternary opcode
    [[nodiscard]] T operator()(Sym n, const T& a, const T& b, const T& c)
    {
        auto p = fTriFuncs.find(n);
        if (p == fTriFuncs.end()) {
            std::cerr << "Unknown quinary opcode " << n << std::endl;
            exit(-1);
        }
        return std::invoke(p->second, this, a, b, c);
    }

    // call quaternary opcode
    [[nodiscard]] T operator()(Sym n, const T& a, const T& b, const T& c, const T& d)
    {
        auto p = fQuadFuncs.find(n);
        if (p == fQuadFuncs.end()) {
            std::cerr << "Unknown quaternary opcode " << n << std::endl;
            exit(-1);
        }
        return std::invoke(p->second, this, a, b, c, d);
    }

    // call quinary opcodes
    [[nodiscard]] T operator()(Sym n, const T& a, const T& b, const T& c, const T& d, const T& e)
    {
        auto p = fQuinFuncs.find(n);
        if (p == fQuinFuncs.end()) {
            std::cerr << "Unknown quinary opcode " << n << std::endl;
            exit(-1);
        }
        return std::invoke(p->second, this, a, b, c, d, e);
    }

    virtual ~FaustAlgebra() = default;

    FaustAlgebra()
    {
        // building the dispatch tables
        // UNARY METHODS

        // User interface elements
        fUnFuncs[symbol("button")]   = &FaustAlgebra::Button;
        fUnFuncs[symbol("checkbox")] = &FaustAlgebra::Checkbox;

        // Operations
        fUnFuncs[symbol("abs")]       = &FaustAlgebra::Abs;
        fUnFuncs[symbol("inv")]       = &FaustAlgebra::Inv;
        fUnFuncs[symbol("neg")]       = &FaustAlgebra::Neg;
        fUnFuncs[symbol("acos")]      = &FaustAlgebra::Acos;
        fUnFuncs[symbol("acosh")]     = &FaustAlgebra::Acosh;
        fUnFuncs[symbol("asin")]      = &FaustAlgebra::Asin;
        fUnFuncs[symbol("asinh")]     = &FaustAlgebra::Asinh;
        fUnFuncs[symbol("atan")]      = &FaustAlgebra::Atan;
        fUnFuncs[symbol("atanh")]     = &FaustAlgebra::Atanh;
        fUnFuncs[symbol("ceil")]      = &FaustAlgebra::Ceil;
        fUnFuncs[symbol("cos")]       = &FaustAlgebra::Cos;
        fUnFuncs[symbol("cosh")]      = &FaustAlgebra::Cosh;
        fUnFuncs[symbol("exp")]       = &FaustAlgebra::Exp;
        fUnFuncs[symbol("floatcast")] = &FaustAlgebra::FloatCast;
        fUnFuncs[symbol("floor")]     = &FaustAlgebra::Floor;
        fUnFuncs[symbol("intcast")]   = &FaustAlgebra::IntCast;
        fUnFuncs[symbol("log")]       = &FaustAlgebra::Log;
        fUnFuncs[symbol("log10")]     = &FaustAlgebra::Log10;
        fUnFuncs[symbol("mem")]       = &FaustAlgebra::Mem;
        fUnFuncs[symbol("not")]       = &FaustAlgebra::Not;
        fUnFuncs[symbol("remainder")] = &FaustAlgebra::Remainder;
        fUnFuncs[symbol("rint")]      = &FaustAlgebra::Rint;
        fUnFuncs[symbol("sin")]       = &FaustAlgebra::Sin;
        fUnFuncs[symbol("sinh")]      = &FaustAlgebra::Sinh;
        fUnFuncs[symbol("sqrt")]      = &FaustAlgebra::Sqrt;
        fUnFuncs[symbol("tan")]       = &FaustAlgebra::Tan;
        fUnFuncs[symbol("tanh")]      = &FaustAlgebra::Tanh;

        // BINARY METHODS
        fBinFuncs[symbol("add")]   = &FaustAlgebra::Add;
        fBinFuncs[symbol("sub")]   = &FaustAlgebra::Sub;
        fBinFuncs[symbol("mul")]   = &FaustAlgebra::Mul;
        fBinFuncs[symbol("div")]   = &FaustAlgebra::Div;
        fBinFuncs[symbol("mod")]   = &FaustAlgebra::Mod;
        fBinFuncs[symbol("and")]   = &FaustAlgebra::And;
        fBinFuncs[symbol("atan2")] = &FaustAlgebra::Atan2;
        fBinFuncs[symbol("delay")] = &FaustAlgebra::Delay;
        fBinFuncs[symbol("eq")]    = &FaustAlgebra::Eq;
        fBinFuncs[symbol("ge")]    = &FaustAlgebra::Ge;
        fBinFuncs[symbol("gt")]    = &FaustAlgebra::Gt;
        fBinFuncs[symbol("lsh")]   = &FaustAlgebra::Lsh;
        fBinFuncs[symbol("lt")]    = &FaustAlgebra::Lt;
        fBinFuncs[symbol("max")]   = &FaustAlgebra::Max;
        fBinFuncs[symbol("min")]   = &FaustAlgebra::Min;
        fBinFuncs[symbol("ne")]    = &FaustAlgebra::Ne;
        fBinFuncs[symbol("or")]    = &FaustAlgebra::Or;
        fBinFuncs[symbol("pow")]   = &FaustAlgebra::Pow;
        fBinFuncs[symbol("le")]    = &FaustAlgebra::Le;
        fBinFuncs[symbol("rsh")]   = &FaustAlgebra::Rsh;
        fBinFuncs[symbol("xor")]   = &FaustAlgebra::Xor;

        // QUINTARY METHODS
        fQuinFuncs[symbol("vslider")]  = &FaustAlgebra::VSlider;
        fQuinFuncs[symbol("hslider")]  = &FaustAlgebra::HSlider;
        fQuinFuncs[symbol("numentry")] = &FaustAlgebra::NumEntry;
    }
};
