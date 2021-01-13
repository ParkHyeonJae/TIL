#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

class PersonForDeepCopy
{
public:
	PersonForDeepCopy() {}
	explicit PersonForDeepCopy(const char * name, const int age) : age(age)
	{
		const int size = strlen(name) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, name);
	}

	// ±íÀº º¹»ç
	PersonForDeepCopy& operator= (PersonForDeepCopy & ref)
	{
		const int size = strlen(ref.name) + 1;
		this->name = new char[size];

		strcpy_s(this->name, size, ref.name);

		this->age = ref.age;
		return *this;
	}
	// ±íÀº º¹»ç
	PersonForDeepCopy(PersonForDeepCopy& other) : age(other.age)
	{
		const int size = strlen(other.name) + 1;
		this->name = new char[size];

		strcpy_s(this->name, size, other.name);
	}


	~PersonForDeepCopy()
	{
		
		delete[] name;
		name = NULL;
		std::cout << "¼Ò¸êÀÚ È£Ãâ" << "\n";
	}


	void ShowInfo() const
	{
		std::cout << name << " : " << age << "\n";
	}
private:
	char* name;
	int age;
};

// ¾èÀº º¹»ç
class PersonForShallowCopy
{
public:
	PersonForShallowCopy() {}
	explicit PersonForShallowCopy(const int age, const int height) : age(age), height(height)
	{
	}

	~PersonForShallowCopy()
	{
		std::cout << "¼Ò¸êÀÚ È£Ãâ" << "\n";
	}

	void ShowInfo() const
	{
		std::cout << "Age : " << age << "height : " << height << "\n";
	}
private:
	int age;
	int height;
};

int main(void)
{
	PersonForDeepCopy p1("¹ÚÇöÀç", 19);

	PersonForDeepCopy p2;
	p2 = p1;

	p1.ShowInfo();
	p2.ShowInfo();

	PersonForShallowCopy p3(19, 179);
	PersonForShallowCopy p4;

	p4 = p3;
	p3.ShowInfo();
	p4.ShowInfo();

	
	return 0;
}