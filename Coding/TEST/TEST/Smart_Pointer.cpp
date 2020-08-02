#include <iostream>
#include <memory>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person(const string& name, int age);		//기초 클래스 생성자의 선언
	~Person() { cout << "소멸자가 호출되었습니다." << endl; }

	void ShowPersonInfo();
};


int main()
{
	shared_ptr<Person> hong = make_shared<Person>("박현재", 18);
	cout << "현재 소유자 수 : " << hong.use_count() << endl;

	auto han = hong;

	cout << "현재 소유자 수 : " << hong.use_count() << endl;

	han.reset();

	cout << "현재 소유자 수 : " << hong.use_count() << endl;

	return 0;
}

Person::Person(const string& name, int age)
{
	this->name = name;
	this->age = age;
	cout << "생성자가 호출되었습니다." << endl;
}

void Person::ShowPersonInfo()
{
	cout << name << "의 나이는 " << age << "살입니다." << endl;
}
