#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1;
	v1.reserve(20);
	v1.emplace_back(1);
	v1.emplace_back(1);
	v1.emplace_back(1);
	v1.emplace_back(1);
	v1.emplace_back(1);
	std::cout << v1.size() << std::endl;

	/*
	vector �� �� �˾Ƶθ� ������:
	���͸� �����ϰ� �������� reserve�� �� ���ָ� ����.
	������ �˷��� vector�� �޸� ������ �˾ƾߵǴµ�,
	�⺻������ vector���� emplace_back�� �ϰ� �ȴٸ� heap������ 
	���� ������ ������ �ٷ� �ڿ� ������ �ϰ� �Ǵµ� ���� �ڿ� �̹�
	������� �޸𸮰� ���� ��찡 �ִ�.
	�̸� ����ȭ(Fragmentation)��� �ϴµ� �̷� ���ؼ�
	�ٷ� �ڿ� ������ ���� ��쿡�� vector�� size() + 1 ��ŭ�� ����� 
	�Ҵ� ������ ������ �� �Ҵ��� �����ְ� ���� �ִ� ������ ���ο� ������
	copy�� ����, ���� �ִ� ������ ���� ����� �Ѵ�.
	�׷��� �Ǹ� �����ս� ������ ���� vector�� ����� alloc, dealloc�� �߻��ϰ� 
	�Ǹ鼭 �����ս��� ������ �� �� �ִ�. -> emplace_back�� O(n)
	������ ó���� ���� ���� ������ ����ŭ�� ũ�⸦ �������ָ� ó�� �Ҵ��Ҷ�
	�ش� ũ�⸸ ���� ������ ���߿� ����ȭ�� �������� ���� ���Ҵ� ������ 
	�ʿ䰡 ��������. -> emplace_back�� O(1)
	�̶� ������ ũ��(capacity)�� �������ִ� �Լ��� reserve�̴�.
	*/




	// Vector ����ϸ鼭 �Ǽ� �� �� �ִ� �κ�
	std::vector<int> v2;
	v2.reserve(10);
	v2.emplace_back(3);
	v2.emplace_back(4);
	v2.emplace_back(5);
	v2.emplace_back(6);
	v2.emplace_back(7);

	for (auto iter = v2.begin(); iter != v2.end(); iter++)
	{
		std::cout << (*iter) << std::endl;
		v2.emplace_back(5);			// <- ���� �߻� !
	}

	/*
	���� �ڵ带 ���� �Ǽ��� ���� �� �� �ִ� �κ��̴�.
	v2�� iterator�� ó�� ���ۺ��� ������ ���ʷ� �Ѿ�µ�,
	�ڵ� ���� ���� ���� �Ǹ� emplace_back�� �߰��� ���ش�.
	�̰� �� ������ �ǳĸ�, vector �������� ������ size�� capacity��ŭ �Ѿ�� �Ǹ�
	�ڿ� capacity��ŭ ���� �Ҵ����ִµ� �̶� �Ҵ����ִ� ������ �̹� �Ҵ�� ������ �����Ѵٸ�(�ڼ��Ѱ� ����ȭ(Fragmentation)���� ���ؼ� ����)
	������ �ִ� ���� ������ ���ο� ũ�⸦ �Ҵ� ������ ������ ���Ҵ����ִµ� �̶� �����͵� �ٲ�鼭
	������ for�� �ȿ��� ������ �ִ� iteration�� ������ ���� �����ε� �����Ϸ��� �ϱ� ������
	������ �߻��ϰ� �ȴ�.
	������ �̸� �����ϱ� ���ؼ� for(int i = 0; i < v2.size(); i++){} ����� ����ؼ�
	iteration ���� ��� �ݺ��� �ƴ�, �ε��� ������� �ϸ� ������ �߻����� �ʰ� �ȴ�.
	�翬�ϰ����� ������� �ݺ��� (for(auto& v : v2) {})�� iteration���� �����ϱ� ������ ����ϸ� �ȵȴ�.
	*/
	return 0;
}