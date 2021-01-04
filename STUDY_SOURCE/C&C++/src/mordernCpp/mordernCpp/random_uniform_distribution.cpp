#include <iostream>
#include <random>
#include <time.h>

#define ITERATION 20

int main()
{
	// 흔히 인터넷에 치면 나오는 모듈러를 이용한 난수 생성 방식
	/*
	이는 일단 time을 사용하고 모듈러(%)를 통해서 랜덤 값을 
	범위 안에 랜덤 값을 결정하기 때문에 uniform distribution이 
	발생하지 않을 수 있다.
	*/
	srand(time(NULL));
	
	std::cout << "==== rand()활용 난수 ====" << std::endl;
	for (size_t i = 0; i < ITERATION; i++)
	{
		std::cout << rand() % 100 << std::endl;
	}

	std::cout<<std::endl;
	std::cout<<std::endl;

	/*
	때문에 Cpp에서는 mt19937을 통해서 난수 생성 엔진을 생성할 수 있다.
	mt1 생성할 때 시드를 정할 수 있는데, 이때 사용자가 직접 입력을 했을 시
	그 시드를 기점으로 난수가 생성이 되기 때문에 의사 난수가 된다.

	만약 완전한 난수를 발생시키고 싶다면 random_device를 만들어서
	mt의 시드 부분에 넣어주면 된다.
	*/

	std::cout << "==== mt19937 활용 난수(의사 시드) ====" << std::endl;

	std::mt19937 mt1(1234);
	std::uniform_int_distribution<int> uid1(0, 99);

	for (size_t i = 0; i < ITERATION; i++)
	{
		std::cout << uid1(mt1) << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==== mt19937 활용 난수(랜덤 시드) ====" << std::endl;
	std::random_device rd;
	std::mt19937 mt2(rd());
	std::uniform_int_distribution<int> uid2(0, 99);

	for (size_t i = 0; i < ITERATION; i++)
	{
		std::cout << uid2(mt2) << std::endl;
	}
	

	return 0;
}