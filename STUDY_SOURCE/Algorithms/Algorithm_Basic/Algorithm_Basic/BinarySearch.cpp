#include <iostream>
#include <array>

const int MAX_ARRAY = 6;

int Binary_Search(std::array<int, MAX_ARRAY> num, int target)
{
	int left = 0;
	int right = (sizeof(num) / sizeof(int)) - 1;

	while (left <= right)
	{
		int pivot = (left + right) / 2;

		if (num[pivot] == target)
			return pivot;

		if (num[pivot] < target)
		{
			left = pivot + 1;
		}
		else if(target < num[pivot])
		{
			right = pivot - 1;
		}

	}
	return -1;
}


int main(void)
{
	
	std::array<int, MAX_ARRAY> num =
	{
		4,10,11,14,17,20
	};
	auto idx = Binary_Search(num, 11);
	std::cout << idx << "\n";

	return 0;
}