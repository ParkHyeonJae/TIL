#include <iostream>
#include <Windows.h>
#include <memory>
#include <mutex>
#include <vector>

using namespace std;

class Event {
private:
	HANDLE hEvent;

public:
	HANDLE GetEvent() { return hEvent; }

	void CreateEvt(LPCWSTR EvtName);

	DWORD Wait();

	BOOL SetEvt();

	BOOL PulseEvt();
	Event();
	~Event();
}; 
void Event::CreateEvt(LPCWSTR EvtName)
{
	CreateEvent(NULL, TRUE, FALSE, EvtName);
}
DWORD Event::Wait()
{
	return WaitForSingleObject(GetEvent(), INFINITE);
}
BOOL Event::SetEvt()
{
	return SetEvent(hEvent);;
}
BOOL Event::PulseEvt()
{
	return 	PulseEvent(hEvent);
}
Event::Event() : hEvent(nullptr)
{
	
}

Event::~Event()
{
	CloseHandle(hEvent);
}

Event event1;
void Thread1()
{

	event1.Wait();
	
	
}
void Thread2()
{
	event1.Wait();
}
void Thread3()
{
	event1.CreateEvt(L"evt");
	event1.SetEvt();
}

int main(int argc, char ** argv)
{

	thread* thread01 = new thread(Thread1);
	thread * thread02 = new thread(Thread2);
	thread * thread03 = new thread(Thread3);

	(*thread01).join();
	(*thread02).join();
	(*thread03).join();
	return 0;
}

