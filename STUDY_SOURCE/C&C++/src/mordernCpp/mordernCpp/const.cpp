#include <iostream>

constexpr int hello(const int hello);

int main(void)
{
	/*
	�����ϸ� const�� �ִ��� ���� ���̴°� ����.
	const�� ��Ÿ�ӿ� ������ �߰���������,
	constexpr�� ������Ÿ�ӿ� ������ �߰����༭ 
	���� ������ ��������� ���� ������ �߰����༭ constexpr�� ���� �� ����
	����ϴ� �� ����.
	
	������ optimization���� ���Һ��� �Ǽ� ������ ���� ���ҷν� �� ���� ���ȴٰ� �Ѵ�.
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