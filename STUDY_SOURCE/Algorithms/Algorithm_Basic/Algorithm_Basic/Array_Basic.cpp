#include <iostream>
#include <vector>
#include <algorithm>

/*
* 
* 배열이란?
* 
* 같은 데이터 타입이 연속으로 이어져서 Random Access를 지원하는 DataStructure이다.
* 
* Random Access란 a[20], a[2], a[0] 과 같이 인덱스를 통해 바로 접근이 가능한 것을 뜻한다.
* 
* 
* 
*/

struct Human
{
	int age;
	char Grade;
};


bool operator< (const Human& lhs, const Human& rhs)
{
	return lhs.age < rhs.age;
}

int main(void)
{
	std::vector<Human> v 
	{
		{200, 'A'},
		{200, 'B'},
		{200, 'C'},
		{200, 'D'},
		{200, 'E'},
	};

	for (int i = 9; i < 100; i++)
	{
		v.emplace_back(Human{ i, 'Z' });
	}
	std::stable_sort(v.begin(), v.end());
	//std::sort(v.begin(), v.end());\


	for (auto& i : v)
	{
		std::cout << i.age << " , " << i.Grade << "\n";
	}

	return 0;
}