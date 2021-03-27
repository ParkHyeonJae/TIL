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

	if (IsDog)		// �̷������� Ư�� ���ǿ� ���� �� Ŭ������ ���¸� �������´ٸ� Inheritance�� ����Ͽ� Dynamic function binding�� ����ص� ��.
		animal = std::make_shared<Dog>();
	else animal = std::make_shared<Cat>();

	animal->Speak();


	Dog dog;
	Cat cat;

	dog.Speak();		// �ݴ�� �̷������� �����ϰ� ����� �ҰŸ� ��Ӿ��� �׳� ���°� ������������ ���ٰ� �Ѵ�.
	cat.Speak();

	return 0;
}