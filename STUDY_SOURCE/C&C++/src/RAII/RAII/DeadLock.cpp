#include <thread>
#include <future>
#include <mutex>

std::mutex gMutexA;
std::mutex gMutexB;

std::recursive_mutex gMutex_recursive;
int sharedMemA = 0;
int sharedMemB = 0;

// 아래와 같이 상호 쓰레드간에 엇갈리는 순서로 lock을 걸어주면 한쪽은 이미 lock이 되어있는데, 다른 한 쪽도 이미 lock을 해둬서 DeadLock이 걸려버리게 된다.
//void Foo()
//{
//	std::lock_guard<std::mutex> lock1(gMutexA);
//	sharedMemA++;
//
//	std::lock_guard<std::mutex> lock2(gMutexB);
//	sharedMemB--;
//
//
//}
//
//void Bar()
//{
//	std::lock_guard<std::mutex> lock2(gMutexB);
//	sharedMemB--;
//
//	std::lock_guard<std::mutex> lock1(gMutexA);
//	sharedMemA++;
//
//}


// 

//void Bar();
//void Foo()
//{
//	std::lock_guard<std::recursive_mutex> lock1(gMutex_recursive);
//	sharedMemA++;
//	
//	Bar();		// 또한 이 처럼 같은 뮤텍스를 또다시 lock을 걸어주려고 하면 self deadlock에 걸리게 된다.
//	// 따라서 이러한 구조는 피해야 되지만 이런 구조를 어쩔 수 없이 사용해야 되는 구조라면 std::recursive_mutex를 사용하면 된다.
//}
//
//void Bar()
//{
//	std::lock_guard<std::recursive_mutex> lock1(gMutex_recursive);
//	sharedMemB--;
//
//}

void Foo()
{
	// scopeed_lock을 사용해서 한번에 여러개의 mutex를 담을 수 있어서 이를 통해서 deadLock이 일어나는 실수를 일부 막을 수 있다.
	std::scoped_lock lock1(gMutexA, gMutexB);
	sharedMemA++;
	sharedMemB--;


}

void Bar()
{
	std::scoped_lock lock1(gMutexA, gMutexB);
	sharedMemA++;

}

int main(void)
{
	std::future<void> f1 = std::async(std::launch::async, Foo);
	std::future<void> f2 = std::async(std::launch::async, Bar);

	//std::thread t1(Foo);
	//std::thread t2(Bar);

	//t1.join();
	//t2.join();

	f1.get();
	f2.get();

	return 0;
}

