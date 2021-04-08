#include "Dog.hpp"
#include "Dog.hpp"

#include <iostream>

extern "C"{
void Speak()
{

}
}


void Speak(int i, int ii)
{

}
int main(void)
{
    Dog dog;
    dog.Speak();
    Speak();
    Speak(1, 11);

    
    std::cout << __DATE__ << "\n";
    std::cout << __LINE__ << "\n";
    std::cout << __TIME__ << "\n";
    return 0;
}