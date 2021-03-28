#include <condition_variable>
#include <thread>
#include <mutex>
#include <iostream>

std::condition_variable cv;
std::mutex gMutex;
bool condition = 0;
void Foo()
{
	std::unique_lock lock(gMutex);

	cv.wait(lock, []() -> bool {return condition == 1; });		// wait일 때는 unlock을 시켜주게 되고 condition 이 맞게떨어지게 되면 lock을 얻게 된다.

	std::cout << "lock is acquired";

	lock.unlock();
}

int main(void)
{
	std::thread t1(Foo);
	{
		std::scoped_lock lock(gMutex);
		condition = 1;
	}
	cv.notify_one();

	t1.join();


	return 0;
}