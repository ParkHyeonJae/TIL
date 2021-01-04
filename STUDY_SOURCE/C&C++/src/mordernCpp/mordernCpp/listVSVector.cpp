#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> l1;
	std::vector<int> v1;

	l1.emplace_back(1);
	l1.emplace_back(2);
	l1.emplace_back(3);
	l1.emplace_back(4);

	v1.emplace_back(1);
	v1.emplace_back(2);
	v1.emplace_back(3);
	v1.emplace_back(4);

	for (auto& l : l1) {
		std::cout << l << std::endl;
	}

	std::cout << "==============" << std::endl;

	for (auto& v : v1) {
		std::cout << v << std::endl;
	}
	
	/*
	list vs vector

	search:
	list -> O(n)
	vector -> O(n)

	insertion:
	list -> O(1)
	vector -> O(n)

	deletion:
	list -> O(1)
	vector -> O(n)

	���� ���븸 ������ list�� �ð����⵵
	insertion�� deletion�� �󵵸� ����ϸ� O(1)�̱� ������
	list�� ���°� �� �̷ο� �������� ������ cache line������
	vector�� ����ϴ°� �� ���ٰ� �Ѵ�.
	vector�� cache line�� �����Ǳ� ������ ���� ������ ��������
	list�� heap�� �Ҵ�Ǵ� ������ cache line ������ �Ҵ�Ǵ�
	������ �����ֱ� ������ �� ��츦 ����ϸ� vector�� ����ϴ°� 
	�� ���ٰ� �Ѵ�.

	insertion �� deleteion�� �������� ���� 
	vector���� listó�� O(1)�� ������ ��찡 �ִ�.
	�ٷ� �� ���κп� emplace_back�� ���� insertion�� ���ְų�
	�߰��� �����ϰ� �� ���� �ִ� ���� move�� ���� �Ű��ָ�
	O(1)�� Time complexity�� �߻��ϰ� �ȴ�.
	������ �̷��� �Ǹ� ������ ���� ���谡 ���� �� �ִٴ� ���� �˵��� ����.
	
	*/
	return 0;
}