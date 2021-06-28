#include <iostream>
#include <variant>

/*

빌드
g++ build.cpp -> a.exe

g++ build.cpp -o greeting       -> greeting.exe

g++ build.cpp -o greeting -Wall -> greeting.exe, Warning Check

g++ build.cpp -o greeting -Wall -Werror -> greeting.exe, Warninig 발생시 빌드 X

*/

int main(void)
{
    int i = 0;      // not Initalized
    std::cout << "HI" << std::endl;

    std::variant<int, float> ii = 0;        // C++17
    
    return 0;
}