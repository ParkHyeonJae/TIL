#include <thread>
#include <iostream>
#include <mutex>


std::mutex gMutex;
int sum = 0;

void Add(int num)
{
	{
		//std::lock_guard<std::mutex> gGuard(gMutex);		//���� RAII�� ����Ͽ� mutex�� unlock���� �ʴ� �Ǽ��� ������ �� �ִ�.
		std::scoped_lock<std::mutex> gScope(gMutex);
		//gMutex.lock();		// ���� �̸� lock�ؼ� �ϳ��� �����常 ������ �� �ֵ��� �ϰ� ������ �����尡 �����Ϸ��� �ϸ� wait�� �ϵ��� ���� �� �ִ�.
		sum += num;		// �ϳ��� �޸� �ڿ��� ���� �����忡�� �����ؼ� ����� ��, �̶� Race Condition �� �߻��� ���ɼ��� ����.
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