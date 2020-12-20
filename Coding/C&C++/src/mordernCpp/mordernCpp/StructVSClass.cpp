#include <iostream>

/// <summary>
/// struct 에서는 default 접근이 public이기 때문에 따로 접근제어를 하지 않아도 접근이 가능하다.
/// 하지만 class는 struct와는 반대로 default가 private라서 바로 접근이 불가능하고 public 으로 해줘야만 접근이 가능하다.
/// </summary>
struct stPerson
{
	void SetAge(int age) { this->age = age; }
	int GetAge() { return age; }

	void SetName(const char const * name) { this->name = name; }
	const char* GetName() { return name; }

	void Print();

	stPerson()
	{
		std::cout << "struct 생성" << std::endl;
		name = "nameless";
		age = 0;
	}
	~stPerson()
	{
		std::cout << "struct 소멸" << std::endl;
	}
private:
	const char* name;
	int age;
};
void stPerson::Print()
{
	std::cout << GetName() << " : " << GetAge() << std::endl;
}
class clPerson
{
public:
	void SetAge(int age) { this->age = age; }
	int GetAge() { return age; }

	void SetName(const char const* name) { this->name = name; }
	const char* GetName() { return name; }

	void Print();

	clPerson()
	{
		name = "nameless";
		age = 0;
	}
	~clPerson()
	{
		std::cout << "struct 소멸" << std::endl;
	}

private:
	const char* name;
	int age;
};
void clPerson::Print()
{
	std::cout << GetName() << " : " << GetAge() << std::endl;
}



template<int a1, int a2>
struct Add {
	enum { value = a1 + a2; };
};


int main()
{
	stPerson stperson;
	int stAge = 20;
	stperson.SetAge(stAge);
	stperson.SetName("Park Hyun Jae");
	stAge = 30;
	stperson.Print();

	clPerson person;
	int age = 20;
	person.SetAge(age);
	person.SetName("Park Hyun Jae");
	age = 30;
	person.Print();

	Add<60, 20> result;
	result.value;
	return 0;
}
