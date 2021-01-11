#include <iostream>
#include <vector>
#include <deque>



int main(void)
{
	/*
	* deque (double-ended queue) -> 양쪽에 queue가 있는 자료구조
	* 랜덤 엑세스 - O(1)
	* 처음과 끝 삽입 & 제거 - O(1)
	* 요소 삽입 & 제거 - O(n)
	* 
	* vector
	* 랜덤 엑세스 - O(1)
	* 끝 삽입 & 제거 - O(1)
	* 요소 삽입 & 제거 - O(n)
	* 
	* deque는 벡터의 단점인 복사와 단편화를 줄인 버전
	* 원래 벡터는 원소가 개수가 기존의 capacity를 넘기게 되면 reallocation을 하게 되는데
	* 이때 배열 전체를 새로 다시 할당해야 되기 때문에 비용이 많이 소모되는 단점이 있었다.
	* 때문에 덱(deque)은 이를 보완한 자료구조인데,
	* 원소가 추가되어 공간이 부족해졌을 때 전체를 다시 재할당하는 것이 아닌,
	* 새로운 메모리 블록(일명 청크(chunk))을 할당해줘서 그 할당된 곳에 집어넣는 식으로 진행되기 때문에
	* vector 보다 일관된 성능을 보여준다.
	* deque에는 시작점과 끝점을 가리키는 begin, end 가 있고, 연속된 메모리 공간 대신
	* chunk 0 , chunk 1, chunk 2 이런식으로 이루어져 있다.
	* deque로도 직접 index를 가리킬 수 있는데, 이때 deque는
	* chunk 개념으로 뭉쳐저 있기 때문에 해당 인덱스가 어느 청크에 위치한지 계산할 필요가 있다.
	* 
	* 하지만 deque역시 약점이 있는데, vector와 비교했을 때 deque는
	* 청크를 새로 만들게 되면 기존의 Memory Cache line에서 벗어난 곳에
	* alloc이 될 수도 있기 때문에 지역성이 떨어지는 문제가 있다.
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