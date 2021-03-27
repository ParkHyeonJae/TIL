#include <iostream>
#include <memory>

class Name
{
public:
	Name(std::string str) : name(std::move(str)) {}
	Name() =  default;
private:
	std::string name;
};

class Animal
{
public:
	virtual void Speak() = 0;
};

class Dog : public Animal		// Is - A
{
public:
	void Speak() override
	{
		std::cout << "Bark!";
	}
private:

	Name name;		// Has-A
};



class Cat : public Animal
{
public:
	void Speak() override
	{
		std::cout << "Meow !";
	}
};



int main(void)
{
	std::shared_ptr<Animal> animal;

	bool IsDog = true;

	if (IsDog)		// 이런식으로 특정 조건에 따라서 그 클래스의 형태를 결정짓는다면 Inheritance를 사용하여 Dynamic function binding을 사용해도 됨.
		animal = std::make_shared<Dog>();
	else animal = std::make_shared<Cat>();

	animal->Speak();


	Dog dog;
	Cat cat;

	dog.Speak();		// 반대로 이런식으로 간단하게 사용을 할거면 상속없이 그냥 쓰는게 유지보수성이 좋다고 한다.
	cat.Speak();

	return 0;
}