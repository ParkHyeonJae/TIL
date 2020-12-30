#include <iostream>
#include <stddef.h>

struct Resource {
	char b;
	int a;
};

int main()
{
	Resource* r1 = new Resource();
	//char 하나랑 int 하나가 합쳐져서 1 + 4 = 5byte 가 나와야 되는데 결과는 8byte가 나옴
	// 이유는 패딩 때문인데, 구조체를 정렬할 때 남은 공간을 채워지기 때문
	// 채워지는 조건은 가장 큰 자료형의 사이즈의 배수로 계산이 됨
	// 지금 Resource 구조체에 int가 가장 큰 자료형인 4byte 이므로 char의 남은 공간 즉 3byte가 채워진다.
	// 따라서 (1)+(3) + (4) = 8byte가 된다.

	//offsetof는 구조체 멤버의 위치를 구해주는 매그로다.
	// b는 0에 위치하고 패딩으로 3바이트의 남는공간이 채워졌기 때문에 a는 (1 + 3) 즉 1이 아닌, 4에 위치하게 된다.
	std::cout << offsetof(Resource, b) << std::endl;
	std::cout << offsetof(Resource, a) << std::endl;

	
	std::cout << sizeof(*r1) << std::endl;
	delete r1;
	return 0;
}