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
	vector 쓸 때 알아두면 좋은점:
	벡터를 선언하고 쓰기전에 reserve를 꼭 해주면 좋다.
	이유를 알려면 vector의 메모리 구조를 알아야되는데,
	기본적으로 vector에서 emplace_back을 하게 된다면 heap영역의 
	원래 생성되 구역의 바로 뒤에 생성을 하게 되는데 만약 뒤에 이미
	사용중인 메모리가 있을 경우가 있다.
	이를 단편화(Fragmentation)라고 하는데 이로 인해서
	바로 뒤에 구역이 있을 경우에는 vector는 size() + 1 만큼의 사이즈를 
	할당 가능한 구역에 재 할당을 시켜주고 원래 있던 구역을 새로운 영역에
	copy한 다음, 원래 있던 구역을 해제 해줘야 한다.
	그렇게 되면 퍼포먼스 때문에 쓰는 vector가 빈번한 alloc, dealloc이 발생하게 
	되면서 퍼포먼스에 영향을 줄 수 있다. -> emplace_back시 O(n)
	때문에 처음에 쓰기 전에 기존에 쓸만큼의 크기를 지정해주면 처음 할당할때
	해당 크기만 들어가기 때문에 나중에 단편화의 영향으로 새로 재할당 시켜줄 
	필요가 없어진다. -> emplace_back시 O(1)
	이때 기존의 크기(capacity)를 지정해주는 함수가 reserve이다.
	*/




	// Vector 사용하면서 실수 할 수 있는 부분
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
		v2.emplace_back(5);			// <- 문제 발생 !
	}

	/*
	위에 코드를 보면 실수를 자주 할 수 있는 부분이다.
	v2의 iterator를 처음 시작부터 끝까지 차례로 넘어가는데,
	코드 블럭 안을 보게 되면 emplace_back로 추가를 해준다.
	이게 왜 문제가 되냐면, vector 성질에는 기존의 size가 capacity만큼 넘어가게 되면
	뒤에 capacity만큼 새로 할당해주는데 이때 할당해주는 영역에 이미 할당된 구역이 존재한다면(자세한건 단편화(Fragmentation)현상에 대해서 참고)
	기존에 있던 곳을 버리고 새로운 크기를 할당 가능한 영역에 재할당해주는데 이때 포인터도 바뀌면서
	기존에 for문 안에서 돌리고 있는 iteration은 이전의 영역 구간인데 접근하려고 하기 때문에
	문제가 발생하게 된다.
	때문에 이를 방지하기 위해서 for(int i = 0; i < v2.size(); i++){} 방식을 사용해서
	iteration 접근 기반 반복이 아닌, 인덱스 기반으로 하면 문제가 발생하지 않게 된다.
	당연하겠지만 범위기반 반복문 (for(auto& v : v2) {})도 iteration으로 접근하기 때문에 사용하면 안된다.
	*/
	return 0;
}