#include <iostream>
#include <array>
#include <vector>

int main()
{
	int arrSize;

	// C Style -> Static Array
	/*
	정적으로 되어있기 때문에 컴파일 타임에 반드시 MaxSize를 정해줘야 한다.
	Stack 영역에 할당되기 때문에 속도 빠름
	scope가 끝나는 동시에 자동으로 파괴됨
	*/
	int sArray[3] = { 20, 30, 40 };		// Stack
	arrSize = sizeof(sArray) / sizeof(int);

	// C Style -> Dynamic Array
	/*
	동적으로 되어있기 때문에 런타임에 사이즈가 정해지고 MaxSize를 정해줄 필요가 없음
	Heap 영역에 할당되기 때문에 정적으로 되어있는 것보다 느림
	scope가 끝나더라도 파괴되지 않기 때문에 수동으로 반드시 delete[] 를 해줘야 함, 빼먹을 시 Memory leak 이 발생 위험이 있음
	때문에 C Style도 객체를 사용할 때 Destructor 에 delete를 넣는 경우가 많음
	*/
	int* dArray = new int[3];			// Heap
	arrSize = _msize(dArray) / sizeof(int*);		// Array Size
	delete[] dArray;

	// Mordern Style -> Static Array
	/*
	정적으로 되어있기 때문에 컴파일 타임에 반드시 MaxSize를 정해줘야 한다.
	Stack 영역에 할당되기 때문에 속도 빠름
	scope가 끝나는 동시에 자동으로 파괴됨
	CStyle 정적 배열과는 다르게 std::min, std::max, size 등이 있기 때문에 편리하다.
	*/
	std::array<int, 3> sMordernArray = { 10,20,30 };		// Stack
	arrSize = sMordernArray.size();

	// Mordern Style -> Dynamic Array
	std::vector<int> dMordernArray;		// Heap
	/*
	동적으로 되어있기 때문에 런타임에 사이즈가 정해지고 MaxSize를 정해줄 필요가 없음
	Heap 영역에 할당되기 때문에 정적으로 되어있는 것보다 느림
	CStyle 동적 배열과는 다르게 Heap에 선언되어 있는데로 불구하고 수동으로 파괴해줄 필요 없음
	iterater, size 등이 있기 때문에 여러면에서 사용하기 편함
	*/
	dMordernArray.emplace_back(std::move(sArray[0]));
	dMordernArray.emplace_back(std::move(sArray[1]));
	dMordernArray.emplace_back(std::move(sArray[2]));
	arrSize = dMordernArray.size();
	std::cout << arrSize << std::endl;


	/*
	static Array 와 dynamic Array 의 사용 경우는
	정적 배열은 사이즈가 정해져 있고, 사용되는 양 또한 적을 때 주로 쓰이며,
	dynamic Array는 사이즈가 정해져 있지 않으며, 여러가지 쓰일 양이 많을 때 주로 사용된다고 한다.
	*/

	return 0;
}