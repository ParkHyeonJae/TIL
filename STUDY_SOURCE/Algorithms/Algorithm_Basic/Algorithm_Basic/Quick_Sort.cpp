#include <iostream>

void PrinArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "\n";
}

template<typename T>
void Swap(T& t1, T& t2)
{
	auto temp = t1;
	t1 = t2;
	t2 = temp;
}

int* QuickSort(int* arr, int left, int right)
{
	
	int pivot = (left + right) / 2;

	int leftIdx = left;
	int rightIdx = right;

	Swap<int>(arr[pivot], arr[rightIdx]);
	pivot = rightIdx;
	rightIdx--;

	while (leftIdx <= rightIdx)
	{
		PrinArr(arr, 6);
		std::cout << "leftIdx : " << leftIdx << ", rightIdx : " << rightIdx << "\n";

		if (arr[pivot] > arr[rightIdx]
			&& arr[pivot] < arr[leftIdx])
		{

			Swap<int>(arr[rightIdx], arr[leftIdx]);
			rightIdx--;
			leftIdx++;
		}


		if (arr[pivot] < arr[rightIdx])
		{
			rightIdx--;
		}

		if (arr[pivot] > arr[leftIdx])
		{
			leftIdx++;
		}
	}

	if (leftIdx > rightIdx)
	{
		Swap<int>(arr[pivot], arr[leftIdx]);

		pivot = leftIdx;

		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}

	return arr;
}


int main(void)
{
	int num[] = {
		12, 22 ,15,31,30,44
	};

	int size = sizeof(num) / sizeof(int);

	auto arr = QuickSort(num, 0, size - 1);

	//for (int i = 0; i < size; i++)
	//{
	//	std::cout << arr[i] << "\n";
	//}


	return 0;
}