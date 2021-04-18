#include <iostream>

class Cat
{
public:

    Cat()
    {

    }

    Cat(int age) : mAge(age) {}

    ~Cat()
    {

    }

    void Speak()
    {

    }
private:
    int mAge;
};

class Zoo
{
public:
Zoo(const int age)  : kitty(age)        // 초기화 리스트로 Cat이 생성되지 않고 바로 넣어짐  CopyElision이 일어남
{
    //kitty = Cat(age);     // Cat이 한번 더 생성됨
}

private:
Cat kitty;
};

int main(void)
{
    Cat cat;
    cat.Speak();

    return 0;
}