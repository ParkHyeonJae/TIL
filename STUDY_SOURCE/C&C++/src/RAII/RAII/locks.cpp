#include <mutex>
#include <thread>
#include <iostream>
#include <Windows.h>

std::mutex my_mutex;
int i = 0;

void print_func() {
	my_mutex.lock();
	std::cout << "Printing from a thread ! -> " << ++i << "\n";
	my_mutex.unlock();
}


//Better Performance
void better_print_func() {
	std::lock_guard<std::mutex> g(my_mutex);
	std::cout << "Printing from better a thread ! -> " << ++i << "\n";
}

//void AcquireSpinLock(volatile LONG* plCount)
//{
//	LONG lOldCount;
//
//	lb_try:
//	lOldCount = _InterlockedCompareExchange(plCount, 1, 0);
//
//	if (lOldCount)
//	{
//		goto lb_try;
//	}
//}
//void ReleaseSpinLock(volatile LONG* plCount)
//{
//	_InterlockedDecrement(plCount);
//}
//LONG g_lSpinLock = 0;
int main()
{
	std::thread t1(print_func);
	std::thread t2(print_func);

	t1.join();
	t2.join();

	std::thread t3(better_print_func);
	std::thread t4(better_print_func);

	t3.join();
	t4.join();

	//AcquireSpinLock(&amp; g_lSpinLock);
	return 0;
}