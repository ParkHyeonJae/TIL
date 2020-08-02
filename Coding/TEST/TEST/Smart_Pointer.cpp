#include <iostream>
#include <memory>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(const string& name, int age);		//���� Ŭ���� �������� ����
	~Person() { cout << "�Ҹ��ڰ� ȣ��Ǿ����ϴ�." << endl; }

	void ShowPersonInfo();
};


int main()
{
	unique_ptr<Person> hong = make_unique<Person>("������", 18);
	hong->ShowPersonInfo();

	return 0;
}

Person::Person(const string& name, int age)
{
	this->name = name;
	this->age = age;
	cout << "�����ڰ� ȣ��Ǿ����ϴ�." << endl;
}

void Person::ShowPersonInfo()
{
	cout << name << "�� ���̴� " << age << "���Դϴ�." << endl;
}
