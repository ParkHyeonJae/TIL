#include <iostream>
#include <array>
#include <vector>

int main()
{
	int arrSize;

	// C Style -> Static Array
	/*
	�������� �Ǿ��ֱ� ������ ������ Ÿ�ӿ� �ݵ�� MaxSize�� ������� �Ѵ�.
	Stack ������ �Ҵ�Ǳ� ������ �ӵ� ����
	scope�� ������ ���ÿ� �ڵ����� �ı���
	*/
	int sArray[3] = { 20, 30, 40 };		// Stack
	arrSize = sizeof(sArray) / sizeof(int);

	// C Style -> Dynamic Array
	/*
	�������� �Ǿ��ֱ� ������ ��Ÿ�ӿ� ����� �������� MaxSize�� ������ �ʿ䰡 ����
	Heap ������ �Ҵ�Ǳ� ������ �������� �Ǿ��ִ� �ͺ��� ����
	scope�� �������� �ı����� �ʱ� ������ �������� �ݵ�� delete[] �� ����� ��, ������ �� Memory leak �� �߻� ������ ����
	������ C Style�� ��ü�� ����� �� Destructor �� delete�� �ִ� ��찡 ����
	*/
	int* dArray = new int[3];			// Heap
	arrSize = _msize(dArray) / sizeof(int*);		// Array Size
	delete[] dArray;

	// Mordern Style -> Static Array
	/*
	�������� �Ǿ��ֱ� ������ ������ Ÿ�ӿ� �ݵ�� MaxSize�� ������� �Ѵ�.
	Stack ������ �Ҵ�Ǳ� ������ �ӵ� ����
	scope�� ������ ���ÿ� �ڵ����� �ı���
	CStyle ���� �迭���� �ٸ��� std::min, std::max, size ���� �ֱ� ������ ���ϴ�.
	*/
	std::array<int, 3> sMordernArray = { 10,20,30 };		// Stack
	arrSize = sMordernArray.size();

	// Mordern Style -> Dynamic Array
	std::vector<int> dMordernArray;		// Heap
	/*
	�������� �Ǿ��ֱ� ������ ��Ÿ�ӿ� ����� �������� MaxSize�� ������ �ʿ䰡 ����
	Heap ������ �Ҵ�Ǳ� ������ �������� �Ǿ��ִ� �ͺ��� ����
	CStyle ���� �迭���� �ٸ��� Heap�� ����Ǿ� �ִµ��� �ұ��ϰ� �������� �ı����� �ʿ� ����
	iterater, size ���� �ֱ� ������ �����鿡�� ����ϱ� ����
	*/
	dMordernArray.emplace_back(std::move(sArray[0]));
	dMordernArray.emplace_back(std::move(sArray[1]));
	dMordernArray.emplace_back(std::move(sArray[2]));
	arrSize = dMordernArray.size();
	std::cout << arrSize << std::endl;


	/*
	static Array �� dynamic Array �� ��� ����
	���� �迭�� ����� ������ �ְ�, ���Ǵ� �� ���� ���� �� �ַ� ���̸�,
	dynamic Array�� ����� ������ ���� ������, �������� ���� ���� ���� �� �ַ� ���ȴٰ� �Ѵ�.
	*/

	return 0;
}