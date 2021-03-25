#include <iostream>
#include <thread>
#include <future>
#include <array>
#include <memory>
#include <chrono>

std::array<int, 4> sums{ 0, 0, 0, 0 };
int main(void)
{
	std::vector<int> nums(10000);
	std::fill(nums.begin(), nums.end(), 1);

	std::vector<std::future<int>> futures;
	futures.reserve(nums.size());


	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	for (size_t i = 0; i < sums.size(); i++)
	{
		const int unitPerSize = nums.size() / sums.size();
		const int loop = (unitPerSize) * (i + 1);
		for (int idx = i * unitPerSize; idx < loop; idx++)
			sums[i] += nums[idx];
	}

	//for (size_t i = 0; i < sums.size(); i++)
	//{
	//	const int unitPerSize = nums.size() / sums.size();
	//	const int loop = (unitPerSize) * (i + 1);

	//	futures.emplace_back(std::async(std::launch::async, [&, i] {
	//		int sum = 0;
	//		for (int idx = i * unitPerSize; idx < loop; idx++)
	//			sum += nums[idx];

	//		return sum;
	//	}));

	//}


	//for (size_t i = 0; i < futures.size(); i++)
	//{
	//	sums[i] = futures[i].get();
	//	std::cout << sums[i] << "\n";
	//}

	for (auto& v : sums)
		std::cout << v << "\n";

	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

	std::chrono::duration<double> sec = end - start;

	std::cout << sec.count() << "\n";

	return 0;
}
