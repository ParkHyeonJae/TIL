#include <iostream>

class stPerson
{
public:
	stPerson(std::string name, int age)
		: name(std::move(name)), age(age) {};
	stPerson(const stPerson& other) 
		: name(other.name), age(other.age) {};
	stPerson(stPerson&& other) noexcept : name(std::move(other.name)), age(other.age) {};

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
	stPerson a{ "ctor", 11 };

	a.Print();
	stPerson b{ a };
	b.Print();
	stPerson c{ std::move(a) }; // Move R Value

	c.Print();

	a.Print(); // ���þȿ� �ִ� a�� name�� move�� ���ؼ� c�� �̵��߱� ������ a�� �����غ��� ����.
	return 0;
}