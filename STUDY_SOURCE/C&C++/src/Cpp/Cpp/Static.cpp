#include <iostream>

class AAA
{
public:
	static int b;
};
int AAA::b = 99;		// C++ 17 이전까지는 멤버로 static을 선언해주면 무조건 정의를 해줘야 했음.

/// <summary>
/// static 키워드를 붙이게 되면 internal linkage라는 의미를 갖기도 하지만 동시에 
/// 메모리의 data 영역에 들어서게 되면서 여러 클래스를 선언하게 되어도 멤버변수에 있는 static int b는 하나의 변수로써 가질 수 있게 된다.
/// 
/// 이는 컴파일 타임에 static int b를 data 영역에 넣어서 나중에 이를 사용하게 되면 load time에서 이를 가져다가 사용하게 된다.
/// </summary>

static int a = 20;

int main(void)
{
	AAA a1;
	AAA a2;
	AAA a3;

	a1.b = 20;

	std::cout << a3.b;

	return 0;
}