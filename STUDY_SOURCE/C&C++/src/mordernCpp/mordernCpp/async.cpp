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
	* Thread ���� async
	* 
	* async�� ��� �Ǵ� ����
	* - thread(thread based)�� ��Ƽ����Ʈ���� �����带 ����� Ư���Լ��� ���޹޾Ƽ� �����Ų ������ 
	*	join()�Լ��� ���� ��ٸ��ٰ� �Լ��� ������ �ٸ� ��ƾ���� �Ѿ�� ����̴�.
	* - �ٵ� thread�� ����ϰ� �Ǹ� �Լ��� ��ȯ���� ���� �� ���� �ȴ�.
	* - ���� ó�� ���� �Ұ����ϸ�, ���ܿ� ���� throw�Ǹ� �����尡 ���ĵǰ� �ȴ�.
	* - ���α׷� ������ ������ �ѵ� �̻��� �����带 ����� OverSubscription�� �߻��ϰ� �ȴ�.
	* - Thread�� create�� �� ���� ���� ���� �Ҹ� �ʿ��ϴ�.
	* 
	* �ݸ鿡 async�� ���� �ȴٸ�
	* - async(task based)�� std::task�� ����ϸ�, task based�̴�.
	* - ���� ��ȯ���� ������
	* - ����ó���� �� �� ������
	* - OverSubscription�� �߻����� �ʰ� ���ָ�
	* - �⺻������ thread pool�� ������ ���ش�. (standard library implementation�� ���� �ٸ��ٰ� �Ѵ�)
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