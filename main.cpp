
#include <iostream>
#include <sstream>
#include <string>

#include "TestAlgebra.hh"

void hello()
{
    std::cout << "Hello FaustAlgebra" << std::endl;
}

void test1()
{
    TestAlgebra A;
    std::cout << "Test 1: " << A.Add(A.Mul(A.num(10), A.num(20)), A.num(30)) << std::endl;
}
int main()
{
    hello();
    test1();
    return 0;
}
