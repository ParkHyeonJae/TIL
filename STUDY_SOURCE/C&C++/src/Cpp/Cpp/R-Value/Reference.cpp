#include <functional>
#include <iostream>
void RefTest(int& a1)
{
    a1++;
}


template<typename T>
void RefTempateTest(T a2)
{
    a2++;
}

int main(void)
{
    int t = 0;
    RefTest(std::ref(t));

    std::cout << t << "\n";
    
    int t2 = 0;
    RefTempateTest(std::ref(t2));

    std::cout << t2 << "\n";

    return 0;
}