#include <iostream>
#include <time.h>

void Func(int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t i = 0; i < m; i++)
		{
			[]() -> void {

			}();
		}
	}
}

int main(void)
{
	clock_t startTime = clock();
	#pragma omp parallel for
	for (int i = 0; i < 4; i += 1)
	{
		Func(10, 10000000);
	}
	std::cout << "run TIme : " << clock() - startTime << " millisecond.." << std::endl;
	return 0;
}