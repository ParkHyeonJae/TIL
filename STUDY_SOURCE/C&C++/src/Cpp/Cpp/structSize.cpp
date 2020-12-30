#include <iostream>
#include <stddef.h>

struct Resource {
	char b;
	int a;
};

int main()
{
	Resource* r1 = new Resource();
	//char �ϳ��� int �ϳ��� �������� 1 + 4 = 5byte �� ���;� �Ǵµ� ����� 8byte�� ����
	// ������ �е� �����ε�, ����ü�� ������ �� ���� ������ ä������ ����
	// ä������ ������ ���� ū �ڷ����� �������� ����� ����� ��
	// ���� Resource ����ü�� int�� ���� ū �ڷ����� 4byte �̹Ƿ� char�� ���� ���� �� 3byte�� ä������.
	// ���� (1)+(3) + (4) = 8byte�� �ȴ�.

	//offsetof�� ����ü ����� ��ġ�� �����ִ� �ű׷δ�.
	// b�� 0�� ��ġ�ϰ� �е����� 3����Ʈ�� ���°����� ä������ ������ a�� (1 + 3) �� 1�� �ƴ�, 4�� ��ġ�ϰ� �ȴ�.
	std::cout << offsetof(Resource, b) << std::endl;
	std::cout << offsetof(Resource, a) << std::endl;

	
	std::cout << sizeof(*r1) << std::endl;
	delete r1;
	return 0;
}