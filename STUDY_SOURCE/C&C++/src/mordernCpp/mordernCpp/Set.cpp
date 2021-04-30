#include <iostream>
#include <set>


int main(void)
{
	/*
	* std::set은 "대체로" RB Tree를 기반으로 제작된다.
	* 정확하게 말하면 라이브러리 구현에 따라서 달라진다고 한다.
	* 
	* Tree기반으로 제작되기 때문에
	* 삽입(Insertion), 삭제(Deletion)가 O(logN)이 걸리는 것 같다. 
	* 이는 Tree Rebuild를 위해서 걸리는 시간 복잡도로 추정
	* 특정 값을 찾기(Find) 위해서는 O(logN)이 걸린다.
	* 
	* std::set만의 특정은
	* 중복이 제거되기 때문에 동일한 원소를 추가해도 set에 변화가 없고,
	* 항상 정렬이 되어있다.
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