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

	a.Print(); // 스택안에 있는 a의 name은 move를 동해서 c로 이동했기 때문에 a를 실행해봐도 없다.
	return 0;
}