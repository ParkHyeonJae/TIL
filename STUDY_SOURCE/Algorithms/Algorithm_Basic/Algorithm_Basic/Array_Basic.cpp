#include <iostream>
#include <vector>
#include <algorithm>

/*
* 
* �迭�̶�?
* 
* ���� ������ Ÿ���� �������� �̾����� Random Access�� �����ϴ� DataStructure�̴�.
* 
* Random Access�� a[20], a[2], a[0] �� ���� �ε����� ���� �ٷ� ������ ������ ���� ���Ѵ�.
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