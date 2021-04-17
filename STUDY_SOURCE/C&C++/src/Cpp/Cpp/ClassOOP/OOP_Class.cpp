#include <iostream>

class Cat
{
public:
    void SetAge(const int mAge);
    int GetAge() const;
    void Speak();
private:
    int mAge;
};

void Cat::SetAge(const int mAge)
{
    this->mAge = mAge;
}

int Cat::GetAge() const
{
    return this->mAge;
}

void Cat::Speak()
{
    std::cout << "Meow" << "\n";
}


class Animal
{
    public:
    void Speak();
    private:
    int mAge;
}

class Human : public Animal
{
    public:
    void Eat();
};

int main(void)
{
    /*
        Class - Cat : Definition
        Object - cat1, cat2

        class는 설계도와 같은 것이며, Object는 설계도를 바탕으로 만들어낸 실질적으로 메모리에 존재하여 사용되는 요소이다.
        고양이를 예를 들면 고양이란 추상적인 요소를 나이, 울음소리와 같이 정의할 수 있다. 
        OOP는 이러한 고양이, 동물과 같은 추상적인 개념을 오브젝트 단위로 설계하여 사용하는 하나의 패러다임을 말한다. 


        OOP에는 추상화(Abstraction), 캡슐화(Encapsulation), 상속(Inheritance), 다형성(Polymorphism)으로 구성이 되어있다.
        추상화(Abstraction)은 고양이, 동물과 복잡한 자료, 모듈, 시스템으로부터 핵심적인 개념 또는 기능을 간추려 내는 것을 말하며,

        캡슐화(Encapsulation)은 나이나 성별같은 정보를 private으로 해줘서 정보를 외부에게 공개하지 않도록 하여 사용하기 더 쉽도록 하는 것이다.

        상속(Inheritance)는 하위의 요소가 상위의 요소에 존재하는 내용들을 그대로 이어받아서 사용할 수 있다.

        다형성(Polymorphism)은  오버로딩과 오버라이딩이 있는데, 하나의 타입으로 다양한 결과를 얻을 수 있다.


    */

    Cat cat1;
    Cat cat2;

    cat1.SetAge(20);
    cat1.GetAge();
    cat2.Speak();


    Human human;
    human.Eat();
    human.Speak();
    return 0;
}