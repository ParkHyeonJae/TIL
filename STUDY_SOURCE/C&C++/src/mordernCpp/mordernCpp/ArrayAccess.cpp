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
	ù��°�� �ι�°���� �� ��������

	��ǻ�� CPU������ L1, L2, DRAM ���� �����ϴµ�, ���� ���, L1�� �ҷ����� Cache Line���� 64byte(��ǻ�� ���� �ٸ�)��
	�ҷ������� �ȴ�.
	�̶� ù��° ���� Cache Line�� �帧�� �����ϰ� �ҷ����� ������ �ӵ��� CASE 2���� 100�� �� �������� �ȴ�.
	���� �迭 ������ �Ҷ�, Cache Line�� �帧�� ���鼭 ������ �ؾ� �Ѵ�.
	*/
	return 0;
}