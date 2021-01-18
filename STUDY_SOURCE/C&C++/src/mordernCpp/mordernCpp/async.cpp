#include <thread>
#include <future>
#include <iostream>

#pragma warning(disable: 4996)

namespace {
	void foo()
	{
		std::cout << "excuting function.." << std::endl;
		_sleep(2000);
	}
	const int sum(const int a, const int b)
	{
		return a + b;
	}
}
int main(void)
{
	/*
	* Thread 보단 async
	* 
	* async를 써야 되는 이유
	* - thread(thread based)는 멀티쓰레트에서 쓰레드를 만들고 특정함수를 전달받아서 실행시킨 다음에 
	*	join()함수를 통해 기다리다가 함수가 끝나면 다른 루틴으로 넘어가는 방식이다.
	* - 근데 thread를 사용하게 되면 함수의 반환값을 받을 수 없게 된다.
	* - 예외 처리 또한 불가능하며, 예외에 만약 throw되면 쓰레드가 폭파되게 된다.
	* - 프로그램 내에서 정해진 한도 이상의 쓰레드를 만들면 OverSubscription이 발생하게 된다.
	* - Thread를 create할 때 또한 많은 성능 소모가 필요하다.
	* 
	* 반면에 async를 쓰게 된다면
	* - async(task based)는 std::task를 사용하며, task based이다.
	* - 따라서 반환값이 있으며
	* - 예외처리를 할 수 있으며
	* - OverSubscription이 발생하지 않게 해주며
	* - 기본적으로 thread pool로 관리를 해준다. (standard library implementation에 따라 다르다고 한다)
	*/

	std::thread t1(foo);
	t1.join();
	std::cout << "Thread Fin" << std::endl;

	
	std::future<void> a1 = std::async(std::launch::async, foo);
	a1.wait();
	std::cout << "async Fin" << std::endl;


	std::future<int> sumAsync = std::async(std::launch::async, sum, 10, 20);
	
	int result = sumAsync.get();

	std::cout << result << std::endl;

	return 0;
}