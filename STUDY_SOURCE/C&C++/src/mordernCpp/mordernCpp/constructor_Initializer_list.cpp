#include <string.h>

class AAA
{
public:
	AAA() = default;
	AAA(const char* str) {
		strcpy_s(this->str, strlen(str) + 1, str);
	}

private:
	char* str;
};

//생성자 초기화 리스트 사용
class UsingCtorInitalizerList
{
public:
	UsingCtorInitalizerList(int age) : m_Age(age), m_AAA("Hello") {};
private:
	int m_Age;
	AAA m_AAA;
};

// 생성자 초기화 리스트 사용 안함
class NoneUsingCtorInitalizerList
{
public:
	NoneUsingCtorInitalizerList(int age)
	{
		m_Age = age;
		this->m_AAA = AAA("Hello");
	}

private:
	int m_Age;
	AAA m_AAA;
};




int main(void)
{
	/*
	생성자 초기화 리스트를 사용해라

	일반적인 생성자 초기화보다 생성자 초기화 리스트를 사용하는게 더 속도면에서 빠르다.
	
	생성자 초기화리스트를 사용을 안한 상태일때 오브젝트가 만들어지면 int형 m_Age와
	AAA 형태의 m_AAA오브젝트가 만들어짐과 동시에 constructor가 호출되고,
	생성자 안에서 한번더 AAA가 호출되서 총 2번이 호출되는 반면에

	생성자 초기화 리스트를 사용하면 단 1번으로 호출과 동시에 생성자 초기화가 되기때문에
	속도면에서 더 빨라진다.
	*/
	UsingCtorInitalizerList i(10);
	NoneUsingCtorInitalizerList i(10);



	return 0;
}
