#include <thread>

void func3()
{
	int a = 0;
}
void func2()
{
	func3();
}
void func1()
{
	func2();
}

void ThreadProc(int args) {
	func3();
}


void main()
{
	std::thread t1(ThreadProc, 123);


	
	func1();
	t1.join();
}


