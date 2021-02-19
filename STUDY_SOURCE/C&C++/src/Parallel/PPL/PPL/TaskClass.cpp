#include <ppltasks.h>
#include <iostream>

using namespace concurrency;

int wmain(void)
{
	task<int> t([]() {
		return 42;
	});

	t.wait();		// get()메서드도 task의 종료를 대기하기 때문에 생략이 가능하다고 한다.

	std::wcout << t.get() << "\n";


	auto t1 = create_task([]() -> int {
		return 55;
	});

	std::wcout << t1.get() << "\n";


	auto t2 = create_task([]()->int {		// antecedent
		return 99;
	});

	auto t3 = t2.then([](int result) {		// Continuation Tasks
		std::wcout << result << "\n";
	});
	t3.wait();		//continuation

	// Task Chain

	auto plusTask = create_task([]() -> int {
		return 0;
	});

	auto increment = [](int n) {return n + 1; };

	int result = plusTask.then(increment).then(increment).then(increment).get();		// Value-Based Continuations
	std::wcout << "plusTask result : " << result << "\n";


	auto t4 = create_task([]() -> int {return 1234; });

	t4.then([](task<int> result) {											///Task-Based Continuation
		std::wcout << result.get() << "\n";
	}).wait();
	return 0;
}