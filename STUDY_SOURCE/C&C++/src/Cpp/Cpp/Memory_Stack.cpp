#include <iostream>

class Dog
{

};

class Cat
{
public:
	Cat() : age(1)
	{

	}

	~Cat()
	{

	}

	void AddAge(int amount)
	// ��������� ��쿡�� ���� ��Ҹ� ����Ű�� this�� ���� ������ Stack Frame�� ���� �ȴ�.
	{
		age += amount;
	}

private:
	int age = 0;

};

void Foo(int arg)		
// Stack Frame�� �Լ� ������ ���̱� ������ �Լ� �ʵ忡 �ִ� �������� ���̰� �ȴ�
// Stack Frame������ ������ ���� �ִ� ��ҵ�� ���Ҿ argument ������ ������ return���� �� ������ ����Ǿ��� Stack Frame�� Pop�� �ǰ� 
// ���� ����Ǿ��� ��ġ�� ���� ��ġ(Program Counter) �������� ������ �Բ� ���� �ȴ�.
{
	double a;
}

void Bar()
{
	int a;
	int b;
	int c;
}

int main(void)
{
	// STACK : �׿����� ����
	// ���𰡸� ������ �Ǹ� ī�带 �׵��� �������� ������ �Ǹ�,
	// ������ �Ǹ� �� ���� �ִ� ��Ҹ� ����Ǵ� ������ �����̴�.


	// Stack Frame�� �Լ� ������ ������ �ȴ�.
	// ���̴� ������ �����Ϸ��� �����ش�.

	int a;
	double b;
	float c;		// Stack Frame ���̷� ���̰� �ȴ�.

	Foo(1);
	Bar();

	
	Cat cat;
	cat.AddAge(20);

	return 0;
}