#include <iostream>
#include <array>

template<class T, size_t ROW, size_t COL>
using Matrix = std::array<std::array<T, COL>, ROW>;

#define ROW 10
#define COL 20

int main() {



	Matrix<float, ROW, COL> mat01;
	// CASE 1
	for (size_t x = 0; x < COL; x++)
	{
		for (size_t y = 0; y < ROW; y++)
		{
			mat01[y][x] = 0;
		}
	}
	

	Matrix<float, ROW, COL> mat02;
	// CASE 2 : x100 Better faster than CASE 1
	for (size_t y = 0; y < ROW; y++)
	{
		for (size_t x = 0; x < COL; x++)
		{
			mat02[y][x] = 0;
		}
	}

	/*
	첫번째가 두번째보다 더 느린이유

	컴퓨터 CPU에서는 L1, L2, DRAM 등이 존재하는데, 예를 들어, L1을 불러오면 Cache Line으로 64byte(컴퓨터 마다 다름)이
	불러와지게 된다.
	이때 첫번째 경우는 Cache Line의 흐름을 무시하고 불러오기 때문에 속도가 CASE 2보다 100배 더 느려지게 된다.
	따라서 배열 접근을 할때, Cache Line의 흐름을 보면서 접근을 해야 한다.
	*/
	return 0;
}