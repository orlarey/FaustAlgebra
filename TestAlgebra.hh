#pragma once

#include "FaustAlgebra.hh"

/**
 * TestAlgebra is a FaustAlgebra that do nothing very useful but to count the maximum depth of an expression
 */
class TestAlgebra : public FaustAlgebra<int>
{
    using T = int;

   public:
    // Injections of external values
    T nil() override;
    T num(int x) override;
    T num(double x) override;
    T label(const std::string& s) override;
    T FixPointUpdate(const T& x, const T& y) override;

    // User interface elements
    T Button(const T& name) override;
    T Checkbox(const T& name) override;
    T VSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step) override;
    T HSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step) override;
    T NumEntry(const T& name, const T& init, const T& lo, const T& hi, const T& step) override;

    T Abs(const T& x) override;
    T Add(const T& x, const T& y) override;
    T Sub(const T& x, const T& y) override;
    T Mul(const T& x, const T& y) override;
    T Div(const T& x, const T& y) override;
    T Inv(const T& x) override;
    T Neg(const T& x) override;
    T Mod(const T& x, const T& y) override;
    T Acos(const T& x) override;
    T Acosh(const T& x) override;
    T And(const T& x, const T& y) override;
    T Asin(const T& x) override;
    T Asinh(const T& x) override;
    T Atan(const T& x) override;
    T Atan2(const T& x, const T& y) override;
    T Atanh(const T& x) override;
    T Ceil(const T& x) override;
    T Cos(const T& x) override;
    T Cosh(const T& x) override;
    T Delay(const T& x, const T& y) override;
    T Eq(const T& x, const T& y) override;
    T Exp(const T& x) override;
    T FloatCast(const T& x) override;
    T Floor(const T& x) override;
    T Ge(const T& x, const T& y) override;
    T Gt(const T& x, const T& y) override;
    T IntCast(const T& x) override;
    T Le(const T& x, const T& y) override;
    T Log(const T& x) override;
    T Log10(const T& x) override;
    T Lsh(const T& x, const T& y) override;
    T Lt(const T& x, const T& y) override;
    T Max(const T& x, const T& y) override;
    T Mem(const T& x) override;
    T Min(const T& x, const T& y) override;
    T Ne(const T& x, const T& y) override;
    T Not(const T& x) override;
    T Or(const T& x, const T& y) override;
    T Pow(const T& x, const T& y) override;
    T Remainder(const T& x) override;
    T Rint(const T& x) override;
    T Rsh(const T& x, const T& y) override;
    T Sin(const T& x) override;
    T Sinh(const T& x) override;
    T Sqrt(const T& x) override;
    T Tan(const T& x) override;
    T Tanh(const T& x) override;
    T Xor(const T& x, const T& y) override;
};
