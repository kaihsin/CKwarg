#include <iostream>
#include <string>
#include "ckwarg.hpp"
using namespace std;



static int foo(int a, float b, std::string const &c){
	return (c.size()+a)/b;
}
// wrapping helping:
auto my_foo = adapt(foo,"ta"_arg,"tb"_arg,"tc"_arg);


int main(){

    // using:
    cout <<  my_foo(
                    "tc"_arg = "hello world",
                    "tb"_arg = 0.5,
                    "ta"_arg = 10
                );

    return 0;
}

