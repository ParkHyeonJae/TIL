#include <iostream>

constexpr int hello(const int hello);

int main(void)
{
	/*
	가능하면 const를 최대한 많이 붙이는게 좋다.
	const는 런타임에 오류를 발견해주지만,
	constexpr은 컴파일타임에 오류를 발견해줘서 
	둘이 역할이 비슷하지만 먼저 오류를 발견해줘서 constexpr을 요즘 더 많이
	사용하는 것 같다.
	
	장점은 optimization적인 역할보다 실수 방지를 위한 역할로써 더 많이 사용된다고 한다.
	*/

	const int a = 10;
	const int b = 20;
	const int c = 50;

	constexpr int d = a + 1;

	std::cout << hello(20) << std::endl;

	return 0;
}

constexpr int hello(const int hello)
{
	return hello;
}