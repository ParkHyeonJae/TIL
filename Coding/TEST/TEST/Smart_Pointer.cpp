#include <iostream>
#include <memory>

using namespace std;

int main()
{
	// int 형 shared_ptr인 ptr01을 선언하고 초기화함
	shared_ptr<int> ptr01(new int(5));

	//use_count()는 참조중인 소유자의 수를 반환해 준다
	cout << ptr01.use_count() << endl;		// 1개
	auto ptr02(ptr01);
	cout << ptr01.use_count() << endl;		// 2개
	auto ptr03 = ptr01;
	auto ptr04 = ptr01;
	auto ptr05 = ptr01;
	cout << ptr01.use_count() << endl;		//5개


	return 0;
}