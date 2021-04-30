#include <iostream>
#include <set>


int main(void)
{
	/*
	* std::set�� "��ü��" RB Tree�� ������� ���۵ȴ�.
	* ��Ȯ�ϰ� ���ϸ� ���̺귯�� ������ ���� �޶����ٰ� �Ѵ�.
	* 
	* Tree������� ���۵Ǳ� ������
	* ����(Insertion), ����(Deletion)�� O(logN)�� �ɸ��� �� ����. 
	* �̴� Tree Rebuild�� ���ؼ� �ɸ��� �ð� ���⵵�� ����
	* Ư�� ���� ã��(Find) ���ؼ��� O(logN)�� �ɸ���.
	* 
	* std::set���� Ư����
	* �ߺ��� ���ŵǱ� ������ ������ ���Ҹ� �߰��ص� set�� ��ȭ�� ����,
	* �׻� ������ �Ǿ��ִ�.
	* 
	* 
	*/


	std::set<int> nums{ 1,2,3,4,5,6 };

	nums.emplace(-200);
	nums.emplace(-2000);
	nums.emplace(4);
	nums.emplace(4);
	nums.emplace(4);
	nums.emplace(4);
	nums.emplace(4);
	nums.emplace(8);
	nums.emplace(4000);
	nums.emplace(5000);

	for (auto& num : nums)
	{
		std::cout << num << "\n";
	}

	return 0;
}