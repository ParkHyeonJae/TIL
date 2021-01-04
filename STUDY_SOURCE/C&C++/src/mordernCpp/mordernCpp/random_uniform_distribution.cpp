#include <iostream>
#include <random>
#include <time.h>

#define ITERATION 20

int main()
{
	// ���� ���ͳݿ� ġ�� ������ ��ⷯ�� �̿��� ���� ���� ���
	/*
	�̴� �ϴ� time�� ����ϰ� ��ⷯ(%)�� ���ؼ� ���� ���� 
	���� �ȿ� ���� ���� �����ϱ� ������ uniform distribution�� 
	�߻����� ���� �� �ִ�.
	*/
	srand(time(NULL));
	
	std::cout << "==== rand()Ȱ�� ���� ====" << std::endl;
	for (size_t i = 0; i < ITERATION; i++)
	{
		std::cout << rand() % 100 << std::endl;
	}

	std::cout<<std::endl;
	std::cout<<std::endl;

	/*
	������ Cpp������ mt19937�� ���ؼ� ���� ���� ������ ������ �� �ִ�.
	mt1 ������ �� �õ带 ���� �� �ִµ�, �̶� ����ڰ� ���� �Է��� ���� ��
	�� �õ带 �������� ������ ������ �Ǳ� ������ �ǻ� ������ �ȴ�.

	���� ������ ������ �߻���Ű�� �ʹٸ� random_device�� ����
	mt�� �õ� �κп� �־��ָ� �ȴ�.
	*/

	std::cout << "==== mt19937 Ȱ�� ����(�ǻ� �õ�) ====" << std::endl;

	std::mt19937 mt1(1234);
	std::uniform_int_distribution<int> uid1(0, 99);

	for (size_t i = 0; i < ITERATION; i++)
	{
		std::cout << uid1(mt1) << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==== mt19937 Ȱ�� ����(���� �õ�) ====" << std::endl;
	std::random_device rd;
	std::mt19937 mt2(rd());
	std::uniform_int_distribution<int> uid2(0, 99);

	for (size_t i = 0; i < ITERATION; i++)
	{
		std::cout << uid2(mt2) << std::endl;
	}
	

	return 0;
}