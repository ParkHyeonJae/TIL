#include <stdio.h>
#include <memory>

using namespace std;

int main()
{
	//int 형 unique_ptr인 ptr01을 선언하고 초기화함
	unique_ptr<int> ptr01(new int(5));

	auto ptr02 = move(ptr01);
	ptr02.reset();
	ptr01.reset();
	return 0;
}