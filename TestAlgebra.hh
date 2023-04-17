#pragma once

#include <vector>
#include "FaustAlgebra.hh"

/**
 * TestAlgebra is a FaustAlgebra that do nothing very useful but to count the maximum depth of an expression
 */
class TestAlgebra : public FaustAlgebra<int>
{
    using T = int;

   public:
    // Injections of external values
    T Nil() override;
    T IntNum(int x) override;
    T Int64Num(int64_t x) override;
    T FloatNum(double x) override;
    T Label(const std::string& s) override;

    // Used when searching for fixpoint
    T FixPointUpdate(const T& x, const T& y) override;

    // Input and output
    T Input(const T& c) override;
    T Output(const T& c, const T& x) override;

    // User interface elements
    T Button(const T& name) override;
    T Checkbox(const T& name) override;
    T VSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step) override;
    T HSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step) override;
    T NumEntry(const T& name, const T& init, const T& lo, const T& hi, const T& step) override;
    T Attach(const T& x, const T& y) override;

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
    T Min(const T& x, const T& y) override;
    T Ne(const T& x, const T& y) override;
    T Not(const T& x) override;
    T Or(const T& x, const T& y) override;
    T Pow(const T& x, const T& y) override;
    T Remainder(const T& x) override;
    T Rint(const T& x) override;
    T Rsh(const T& x, const T& y) override;
    T Select2(const T& x, const T& y, const T& z) override;
    T Sin(const T& x) override;
    T Sinh(const T& x) override;
    T Sqrt(const T& x) override;
    T Tan(const T& x) override;
    T Tanh(const T& x) override;
    T Xor(const T& x, const T& y) override;

    // Delays, Tables and SoundFiles
    T Delay1(const T& x) override;
    T Delay(const T& x, const T& y) override;
    T Prefix(const T& x, const T& y) override;
    T RDTbl(const T& wtbl, const T& ri) override;
    T WRTbl(const T& n, const T& g, const T& wi, const T& ws) override;
    T SoundFile(const T& label) override;
    T SoundFileRate(const T& sf, const T& x) override;
    T SoundFileLength(const T& sf, const T& x) override;
    T SoundFileBuffer(const T& sf, const T& x, const T& y, const T& z) override;
    T Waveform(const std::vector<T>& w) override;
};
