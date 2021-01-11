#include <iostream>
#include <vector>
#include <deque>



int main(void)
{
	/*
	* deque (double-ended queue) -> ���ʿ� queue�� �ִ� �ڷᱸ��
	* ���� ������ - O(1)
	* ó���� �� ���� & ���� - O(1)
	* ��� ���� & ���� - O(n)
	* 
	* vector
	* ���� ������ - O(1)
	* �� ���� & ���� - O(1)
	* ��� ���� & ���� - O(n)
	* 
	* deque�� ������ ������ ����� ����ȭ�� ���� ����
	* ���� ���ʹ� ���Ұ� ������ ������ capacity�� �ѱ�� �Ǹ� reallocation�� �ϰ� �Ǵµ�
	* �̶� �迭 ��ü�� ���� �ٽ� �Ҵ��ؾ� �Ǳ� ������ ����� ���� �Ҹ�Ǵ� ������ �־���.
	* ������ ��(deque)�� �̸� ������ �ڷᱸ���ε�,
	* ���Ұ� �߰��Ǿ� ������ ���������� �� ��ü�� �ٽ� ���Ҵ��ϴ� ���� �ƴ�,
	* ���ο� �޸� ���(�ϸ� ûũ(chunk))�� �Ҵ����༭ �� �Ҵ�� ���� ����ִ� ������ ����Ǳ� ������
	* vector ���� �ϰ��� ������ �����ش�.
	* deque���� �������� ������ ����Ű�� begin, end �� �ְ�, ���ӵ� �޸� ���� ���
	* chunk 0 , chunk 1, chunk 2 �̷������� �̷���� �ִ�.
	* deque�ε� ���� index�� ����ų �� �ִµ�, �̶� deque��
	* chunk �������� ������ �ֱ� ������ �ش� �ε����� ��� ûũ�� ��ġ���� ����� �ʿ䰡 �ִ�.
	* 
	* ������ deque���� ������ �ִµ�, vector�� ������ �� deque��
	* ûũ�� ���� ����� �Ǹ� ������ Memory Cache line���� ��� ����
	* alloc�� �� ���� �ֱ� ������ �������� �������� ������ �ִ�.
	* 
	*/
	std::deque<int> dq = { 5,10,15,30,35 };
	std::vector<int> vec;

	dq.emplace_front(3);
	dq.emplace_back(40);
	
	
	std::deque<int>::iterator iter;
	std::deque<int>::iterator end = dq.end();

	for (iter = dq.begin(); iter != end; iter++)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}