#include <iostream>
#include <memory>

using namespace std;

int main()
{
	// int �� shared_ptr�� ptr01�� �����ϰ� �ʱ�ȭ��
	shared_ptr<int> ptr01(new int(5));

	//use_count()�� �������� �������� ���� ��ȯ�� �ش�
	cout << ptr01.use_count() << endl;		// 1��
	auto ptr02(ptr01);
	cout << ptr01.use_count() << endl;		// 2��
	auto ptr03 = ptr01;
	auto ptr04 = ptr01;
	auto ptr05 = ptr01;
	cout << ptr01.use_count() << endl;		//5��


	return 0;
}