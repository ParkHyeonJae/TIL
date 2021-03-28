#include <thread>
#include <future>
#include <mutex>

std::mutex gMutexA;
std::mutex gMutexB;

std::recursive_mutex gMutex_recursive;
int sharedMemA = 0;
int sharedMemB = 0;

// �Ʒ��� ���� ��ȣ �����尣�� �������� ������ lock�� �ɾ��ָ� ������ �̹� lock�� �Ǿ��ִµ�, �ٸ� �� �ʵ� �̹� lock�� �صּ� DeadLock�� �ɷ������� �ȴ�.
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
//	Bar();		// ���� �� ó�� ���� ���ؽ��� �Ǵٽ� lock�� �ɾ��ַ��� �ϸ� self deadlock�� �ɸ��� �ȴ�.
//	// ���� �̷��� ������ ���ؾ� ������ �̷� ������ ��¿ �� ���� ����ؾ� �Ǵ� ������� std::recursive_mutex�� ����ϸ� �ȴ�.
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
	// scopeed_lock�� ����ؼ� �ѹ��� �������� mutex�� ���� �� �־ �̸� ���ؼ� deadLock�� �Ͼ�� �Ǽ��� �Ϻ� ���� �� �ִ�.
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

