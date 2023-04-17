
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
    std::cout << "Test 1: " << A.Add(A.Mul(A.IntNum(10), A.IntNum(20)), A.IntNum(30)) << std::endl;
}
int main()
{
    hello();
    test1();
    return 0;
}
