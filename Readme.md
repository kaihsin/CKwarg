#python like Kwarg in c++

# Requirement:
    
    - boost (hana)
    - c++14 or higher

# To use:

    This is a simple head-only library. Simply include ckwarg.hpp

# example for using:

    Consider a original c++ function foo, we want to use kwargs like python. 
    First, wrapping the function to a lambda, by calling adapt(), with registered keywords.
    Then, the function can be called via "<keyword>"_arg = <value>.

```c++
    #include "ckwarg.hpp"

    static int foo(int a, float b, std::string const &c){
        return (c.size()+a)/b;
    }
    // wrapping helping:
    auto my_foo = adapt(foo,"ta"_arg,"tb"_arg,"tc"_arg);


    int main(){

        // using:
        std::cout <<  my_foo(
                        "tc"_arg = "hello world",
                        "tb"_arg = 0.5,
                        "ta"_arg = 10
                    );

        return 0;
    }
```
    Full example, see main.cpp, use Makefile to build this simple example

# Developer:
    
    Kai-Hsin Wu

# Reference:

    Named Arguments From Scratch by Richard Powell: 
        https://github.com/CppCon/CppCon2018/tree/master/Presentations/named_arguements_from_scratch


