#include <stdio.h>
#include <memory>

using namespace std;

int main()
{
	//int �� unique_ptr�� ptr01�� �����ϰ� �ʱ�ȭ��
	unique_ptr<int> ptr01(new int(5));

	auto ptr02 = move(ptr01);
	ptr02.reset();
	ptr01.reset();
	return 0;
}