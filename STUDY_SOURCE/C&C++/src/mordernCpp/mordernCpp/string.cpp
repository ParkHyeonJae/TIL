#include <iostream>


int main(void)
{
	std::string str = "abc";		// ���̺귯�� ������ ���� �ٸ����� ��� 16byte �Ʒ��� �������� ���ڿ����� heap�� �ƴ�, stack�� alloc�� �Ǳ⶧���� �����ս������� ���� �� �ִ�.

	std::cout << sizeof(str) << std::endl;
	std::string_view sv = "abcdef";		// �ӽð�ü�� �������� �ʰ� ���ڿ��� ����� �� �ִ�.
	std::cout << sv << std::endl;
	return 0;
}