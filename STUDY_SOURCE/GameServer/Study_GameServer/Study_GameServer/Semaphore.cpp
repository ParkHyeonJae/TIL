#include <iostream>
#include <Windows.h>
#include <memory>
#include <mutex>
#include <vector>

using namespace std;

class Semaphore {
private:
	HANDLE hSemaphore;

public:
	HANDLE GetSemaphore() { return hSemaphore; }

	void CreateSema(LONG CriticalSectionCount, LONG maxCount, LPCWSTR SemaName);

	DWORD Wait();
	BOOL ReleaseSema();

	Semaphore();
	~Semaphore();
};
void Semaphore::CreateSema(LONG CriticalSectionCount,LONG maxCount, LPCWSTR SemaName)
{
	hSemaphore = (CreateSemaphore(NULL, CriticalSectionCount, maxCount, NULL));
}
DWORD Semaphore::Wait()
{
	return WaitForSingleObject(GetSemaphore(), INFINITE);
}
BOOL Semaphore::ReleaseSema()
{
	return 	ReleaseSemaphore(GetSemaphore(), 1, 0);
}
Semaphore::Semaphore()
{
}

Semaphore::~Semaphore()
{
	CloseHandle(hSemaphore);
}
HANDLE semaphore;
int main()
{
	semaphore = (CreateSemaphore(NULL, 5, 5, NULL));
	thread t1([&]() {
		while (true) {
			WaitForSingleObject(semaphore, INFINITE);
			cout << "������ 1�� ȭ��� �̿���.." << endl;

			Sleep(2000);

			cout << "������ 1�� ȭ��� �̿� �Ϸ�.." << endl;
			ReleaseSemaphore(semaphore, 1, 0);
		}
		});

	thread t2([&]() {
		while (true) {
			WaitForSingleObject(semaphore, INFINITE);
			cout << "������ 2�� ȭ��� �̿���.." << endl;

			Sleep(2000);

			cout << "������ 2�� ȭ��� �̿� �Ϸ�.." << endl;
			ReleaseSemaphore(semaphore, 1, 0);
		}
		});
	thread t3([&]() {
		while (true) {
			WaitForSingleObject(semaphore, INFINITE);
			cout << "������ 3�� ȭ��� �̿���.." << endl;

			Sleep(2000);

			cout << "������ 3�� ȭ��� �̿� �Ϸ�.." << endl;
			ReleaseSemaphore(semaphore, 1, 0);
		}
		});
	t1.join();
	t2.join();
	t3.join();
	return 0;
}