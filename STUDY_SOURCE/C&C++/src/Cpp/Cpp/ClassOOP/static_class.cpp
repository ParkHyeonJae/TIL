#include <iostream>

class Cat
{
public:
    void speak() const
    {
        static int count = -999;       // static variable in a function
        count++;
        std::cout << "Meow" << " : " << count <<  "\n";
    }

    static void static_speak()      // Static Member Function
    {
        std::cout << "static_Meow" << "\n";
    }
    
private:
    int mAge;
    static int count;       // static member variable
};

int Cat::count = -500;

int main(void)
{
    Cat cat;
    cat.speak();
    cat.static_speak();
    Cat::static_speak();

    Cat cat2;
    cat2.speak();
    return 0;
}