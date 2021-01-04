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

	위에 내용만 봐서는 list의 시간복잡도
	insertion과 deletion의 빈도를 고려하면 O(1)이기 때문에
	list를 쓰는게 더 이로워 보일지도 모르지만 cache line때문에
	vector를 사용하는게 더 좋다고 한다.
	vector는 cache line이 형성되기 때문에 빠른 성능을 보이지만
	list는 heap에 할당되는 구간이 cache line 안으로 할당되는
	보장을 못해주기 때문에 이 경우를 고려하면 vector를 사용하는게 
	더 좋다고 한다.

	insertion 과 deleteion의 관점에서 봐도 
	vector에서 list처럼 O(1)이 가능한 경우가 있다.
	바로 맨 끝부분에 emplace_back을 통해 insertion을 해주거나
	중간에 삭제하고 맨 끝에 있는 것을 move를 통해 옮겨주면
	O(1)의 Time complexity가 발생하게 된다.
	하지만 이렇게 되면 순서에 대한 관계가 깨질 수 있다는 점을 알도록 하자.
	
	*/
	return 0;
}