cmake_minimum_required(VERSION 3.10)

# set the project name
project(test)

set(CMAKE_CXX_STANDARD 20)

if (NOTIDY)
else ()
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,clang-*,cppcoreguidelines-*,-cppcoreguidelines-avoid-magic-numbers,performance-*,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,llvm-*,modernize-*,-modernize-use-trailing-return-type,cert-*")
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()


# add the executable
add_executable(test main.cpp TestAlgebra.cpp tlib/errormsg.cpp tlib/garbageable.cpp tlib/list.cpp tlib/node.cpp tlib/occur.cpp tlib/recursive-tree.cpp tlib/shlysis.cpp tlib/symbol.cpp tlib/tree.cpp)


include_directories(tlib FaustAlgebra)
