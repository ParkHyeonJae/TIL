#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <memory>

using namespace std;

const int MaxCount = 150000;
const int ThreadCount = 4;

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

	auto t0 = chrono::system_clock::now();

	vector<shared_ptr<thread>> threads;
	

	return 0;
}