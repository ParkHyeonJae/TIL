#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <memory>

using namespace std;

const int MaxCount = 150000;
const int ThreadCount = 8;

bool IsPrimeNumebr(int number)
{
	if (number == 1)
		return false;
	if (number == 2 || number == 3)
		return true;

	for (int i = 2; i < number - 1; i++)
	{
		if (i % number == 0)
			return false;
	}

	return true;
}

void PrintNumber(const vector<int>& primes)
{
	for (int v : primes)
	{
		cout << v << endl;
	}
}

int main()
{
	int num = 1;

	vector<int> primes;
	std::recursive_mutex num_mutex;
	std::recursive_mutex prime_mutex;


	auto t0 = chrono::system_clock::now();

	vector<shared_ptr<thread>> threads;

	for (int i = 0; i < ThreadCount; i++)
	{
		shared_ptr<thread> thread(new thread([&]() {
			while (true)
			{
				int n;
				{
					lock_guard<std::recursive_mutex> num_lock(num_mutex);
					n = num;
					num++;
				}
				if (n >= MaxCount)
					break;

				if (IsPrimeNumebr(n))
				{
					{
						lock_guard<std::recursive_mutex> prime_lock(prime_mutex);
						primes.push_back(n);
					}
				}
			}
			}));


		threads.push_back(thread);
	}

	//모든 스레드가 일을 마칠 때까지 기다린다.
	for (auto thread : threads)
	{
		thread->join();
	}

	auto t1 = chrono::system_clock::now();

	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
	//PrintNumber(primes);


	cout << "Took " << duration << " milliseconds." << endl;
	return 0;
}