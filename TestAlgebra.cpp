
#include "TestAlgebra.hh"

using T = int;

T TestAlgebra::nil()
{
    return 1;
}

T TestAlgebra::num(int)
{
    return 1;
}

T TestAlgebra::num(double)
{
    return 1;
}

T TestAlgebra::label(const std::string&)
{
    return 1;
}

T TestAlgebra::FixPointUpdate(const T& x, const T& y)
{
    return std::max(x, y);  // TODO: meaningless !!! see with recursion
}

T TestAlgebra::Button(const T& name)
{
    return 1 + name;
}

T TestAlgebra::Checkbox(const T& name)
{
    return 1 + name;
}

T TestAlgebra::VSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step)
{
    int r = 0;
    for (auto x : {name, init, lo, hi, step}) {
        r = std::max(r, x);
    }
    return 1 + r;
}

T TestAlgebra::HSlider(const T& name, const T& init, const T& lo, const T& hi, const T& step)
{
    int r = 0;
    for (auto x : {name, init, lo, hi, step}) {
        r = std::max(r, x);
    }
    return 1 + r;
}

T TestAlgebra::NumEntry(const T& name, const T& init, const T& lo, const T& hi, const T& step)
{
    int r = 0;
    for (auto x : {name, init, lo, hi, step}) {
        r = std::max(r, x);
    }
    return 1 + r;
}

T TestAlgebra::Abs(const T& x)
{
    return 1 + x;
}

T TestAlgebra::Add(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Sub(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Mul(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Div(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Inv(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Neg(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Mod(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Acos(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Acosh(const T& x)
{
    return 1 + x;
}
T TestAlgebra::And(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Asin(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Asinh(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Atan(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Atan2(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Atanh(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Ceil(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Cos(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Cosh(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Delay(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Eq(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Exp(const T& x)
{
    return 1 + x;
}
T TestAlgebra::FloatCast(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Floor(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Ge(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Gt(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::IntCast(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Le(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Log(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Log10(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Lsh(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Lt(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Max(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Mem(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Min(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Ne(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Not(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Or(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Pow(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Remainder(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Rint(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Rsh(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
T TestAlgebra::Sin(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Sinh(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Sqrt(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Tan(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Tanh(const T& x)
{
    return 1 + x;
}
T TestAlgebra::Xor(const T& x, const T& y)
{
    return 1 + std::max(x, y);
}
