#include <iostream>
#include <array>
#include <vector>
#include <ppltasks.h>
#include <numeric>
#include <memory>

#pragma warning(disable: 4996)
using namespace concurrency;

task<std::wstring> write_to_string();

int wmain(void)
{
	auto t = create_task([]() {
		std::wcout << "Run Task A" << "\n";

		return create_task([]() -> double {
			std::wcout << "Run Task B" << "\n";
			_sleep(2000);
			return 0.2f;
		});
	});
	t.then([](double result) {
		std::wcout << "Run Task C !! : " << result << "\n";
	}).wait();

	std::array<task<int>, 3> tasks =
	{
		create_task([]() -> int {return 88; }),
		create_task([]() -> int {return 77; }),
		create_task([]() -> int {return 55; })
	};

	auto joinTask = when_all(std::begin(tasks), std::end(tasks)).then([](std::vector<int> results) {		// == t1 && t2
		std::wcout << "The Sum Is " << std::accumulate(std::begin(results), std::end(results), 0) << "\n";
	});

	std::wcout << "Joining thread" << "\n";

	joinTask.wait();


	when_any(std::begin(tasks), std::end(tasks)).then([](std::pair<int, size_t> result) {		// Select와 비슷한 느낌, == t1 || t2

		std::wcout << "First task to finish returns" << result.first
			<< "and Index "
			<< result.second
			<< "\n";
	}).wait();


	auto makeStr = write_to_string();

	std::wcout << "Final value : " << makeStr.get() << "\n";

	return 0;
}

task<std::wstring> write_to_string()
{
	auto s = std::make_shared<std::wstring>(L"Value1");

	return create_task([s]() {
		std::wcout << "Current Value : " << *s << "\n";
		*s = L"Value2";

	}).then([s]() {
		std::wcout << "Current Value : " << *s << "\n";
		*s = L"Value3";
		return *s;
	});
}