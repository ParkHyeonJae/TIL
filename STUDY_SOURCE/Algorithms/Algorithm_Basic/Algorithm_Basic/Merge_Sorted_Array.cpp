#include <iostream>

void MergeSortedArray(int *arr1, int remainSize, int size1, int *arr2, int size2)
{
	int num1Pivot = remainSize - 1;
	int writePivot = size1 - 1;
	int num2Pivot = size2 - 1;
	while (0 <= writePivot)
	{
		int num1 = arr1[num1Pivot];
		int num2 = arr2[num2Pivot];

		if (num1 < num2)
		{
			arr1[writePivot] = num2;
			num2Pivot--;
			writePivot--;
		}
		else if(num1 > num2)
		{
			arr1[writePivot] = num1;
			num1Pivot--;
			writePivot--;
		}

		
	}

	while (num2Pivot >= 0)
	{
		arr1[num2Pivot] = arr2[num2Pivot];
		num2Pivot--;
	}


	for (size_t i = 0; i < 6; i++)
	{
		std::cout << arr1[i] << "\n";
	}
}


int main(void)
{
	int num1[] = {
		4, 5, 6, 0, 0, 0
	};
	int num2[] = {
		1, 2, 3
	};
	MergeSortedArray(num1, 3, 6, num2, 3);

	return 0;
}