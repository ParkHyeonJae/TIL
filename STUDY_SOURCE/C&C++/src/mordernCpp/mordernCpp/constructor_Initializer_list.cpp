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

//������ �ʱ�ȭ ����Ʈ ���
class UsingCtorInitalizerList
{
public:
	UsingCtorInitalizerList(int age) : m_Age(age), m_AAA("Hello") {};
private:
	int m_Age;
	AAA m_AAA;
};

// ������ �ʱ�ȭ ����Ʈ ��� ����
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
	������ �ʱ�ȭ ����Ʈ�� ����ض�

	�Ϲ����� ������ �ʱ�ȭ���� ������ �ʱ�ȭ ����Ʈ�� ����ϴ°� �� �ӵ��鿡�� ������.
	
	������ �ʱ�ȭ����Ʈ�� ����� ���� �����϶� ������Ʈ�� ��������� int�� m_Age��
	AAA ������ m_AAA������Ʈ�� ��������� ���ÿ� constructor�� ȣ��ǰ�,
	������ �ȿ��� �ѹ��� AAA�� ȣ��Ǽ� �� 2���� ȣ��Ǵ� �ݸ鿡

	������ �ʱ�ȭ ����Ʈ�� ����ϸ� �� 1������ ȣ��� ���ÿ� ������ �ʱ�ȭ�� �Ǳ⶧����
	�ӵ��鿡�� �� ��������.
	*/
	UsingCtorInitalizerList i(10);
	NoneUsingCtorInitalizerList i(10);



	return 0;
}
