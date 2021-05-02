#include <iostream>

class Animal
{
public:
	Animal()
	{
		std::cout << "animal Constructor" << "\n";
	}

	virtual ~Animal()		// 소멸자를 붙여줘야만 derived된 클래스의 소멸자가 호출된다.
	{
		std::cout << "animal Destructor" << "\n";
	}

	virtual void speak()
	{
		std::cout << "Animal Sound" << "\n";
	}
};

class Dog : public Animal
{
public:
	Dog()
	{
		std::cout << "Dog Constructor" << "\n";
	}

	~Dog()
	{
		std::cout << "Dog Destructor" << "\n";
	}

	void speak() override
	{
		std::cout << "Dog Sound" << "\n";
	}
};

class Cat : public Animal
{
public:
	Cat()
	{
		std::cout << "cat Constructor" << "\n";
	}

	~Cat()
	{
		std::cout << "cat Destructor" << "\n";
	}

	void speak() override
	{
		std::cout << "Cat Sound" << "\n";
	}
};

int main(void)
{
	int N = 0;
	std::cin >> N;
	Animal* animal;
	if(N == 0)
		animal = new Cat();
	else animal = new Dog();

	animal->speak();
	

	delete animal;

	return 0;
}