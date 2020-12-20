#include <iostream>

/// <summary>
/// struct ������ default ������ public�̱� ������ ���� ������� ���� �ʾƵ� ������ �����ϴ�.
/// ������ class�� struct�ʹ� �ݴ�� default�� private�� �ٷ� ������ �Ұ����ϰ� public ���� ����߸� ������ �����ϴ�.
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
		std::cout << "struct ����" << std::endl;
		name = "nameless";
		age = 0;
	}
	~stPerson()
	{
		std::cout << "struct �Ҹ�" << std::endl;
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
		std::cout << "struct �Ҹ�" << std::endl;
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
