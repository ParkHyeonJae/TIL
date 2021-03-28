#include <thread>
#include <iostream>
#include <mutex>


std::mutex gMutex;
int sum = 0;

void Add(int num)
{
	{
		//std::lock_guard<std::mutex> gGuard(gMutex);		//또한 RAII를 사용하여 mutex를 unlock하지 않는 실수를 예방할 수 있다.
		std::scoped_lock<std::mutex> gScope(gMutex);
		//gMutex.lock();		// 따라서 이를 lock해서 하나의 쓰레드만 접근할 수 있도록 하고 나머지 쓰레드가 접근하려고 하면 wait을 하도록 해줄 수 있다.
		sum += num;		// 하나의 메모리 자원을 여러 쓰레드에서 공유해서 사용할 때, 이때 Race Condition 이 발생할 가능성이 높음.
		//gMutex.unlock();
	}
}


int main(void)
{
	std::thread t1(Add, 20);
	std::thread t2(Add, -30);
	std::thread t3(Add, -30);

	t1.join();
	t2.join();
	t3.join();

	std::cout << sum;
	

	return 0;
}