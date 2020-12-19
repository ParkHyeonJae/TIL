#include <iostream>

class Person
{
public:
	Person(std::string name, int age)
		: name(std::move(name)), age(age) {};
	Person(const Person& other) 
		: name(other.name), age(other.age) {};
	Person(Person&& other) noexcept : name(std::move(other.name)), age(other.age) {};

	std::string GetName() {
		return name;
	}
	int GetAge() {
		return age;
	}

	void Print() {
		std::cout << "name : " << GetName() << ", age : " << GetAge() << std::endl;
	}
private:
	std::string name;
	int age;
};



int main()
{
	Person a{ "ctor", 11 };

	a.Print();
	Person b{ a };
	b.Print();
	Person c{ std::move(a) }; // Move R Value

	c.Print();

	a.Print(); // ���þȿ� �ִ� a�� name�� move�� ���ؼ� c�� �̵��߱� ������ a�� �����غ��� ����.
	return 0;
}