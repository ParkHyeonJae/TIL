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
	// 멤버변수의 경우에는 현재 요소를 가리키는 this에 대한 정보도 Stack Frame에 담기게 된다.
	{
		age += amount;
	}

private:
	int age = 0;

};

void Foo(int arg)		
// Stack Frame은 함수 단위로 쌓이기 때문에 함수 필드에 있는 변수들이 쌓이게 된다
// Stack Frame에서는 스코프 내에 있는 요소들과 더불어서 argument 데이터 정보와 return했을 때 기존에 실행되었던 Stack Frame이 Pop이 되고 
// 원래 실행되었던 위치의 다음 위치(Program Counter) 지정해줄 정보도 함께 들어가게 된다.
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
	// STACK : 쌓여가는 느낌
	// 무언가를 들어오게 되면 카드를 쌓듯이 차례차례 들어오게 되며,
	// 나가게 되면 맨 위에 있는 요소를 빼면되는 간단한 구조이다.


	// Stack Frame은 함수 단위로 들어오게 된다.
	// 쌓이는 순서는 컴파일러가 정해준다.

	int a;
	double b;
	float c;		// Stack Frame 단이로 쌓이게 된다.

	Foo(1);
	Bar();

	
	Cat cat;
	cat.AddAge(20);

	return 0;
}