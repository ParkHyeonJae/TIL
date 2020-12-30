#include <mutex>
#include <thread>
#include <iostream>

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

	return 0;
}