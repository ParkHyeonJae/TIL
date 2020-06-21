#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

const int MaxCount = 150000;

bool IsPrimeNumber(int number);
void PrintNumbers(const vector<int> &primes);


int main()
{
	vector<int> primes;

	auto t0 = chrono::system_clock::now();
	
	for (int i = 0; i < MaxCount; i++)
	{
		if (IsPrimeNumber(i))
		{
			primes.push_back(i);
		}
	}

	auto t1 = chrono::system_clock::now();

	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();

	
	PrintNumbers(primes);
	cout << "Took " << duration << " milliseconds." << endl;
	return 0;
}

bool IsPrimeNumber(int number)
{
	if (number == 1)
		return false;
	if (number == 2 || number == 3)
		return true;

	for (int i = 2; i < number - 1; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}
void PrintNumbers(const vector<int> &primes)
{
	for (int v : primes)
	{
		cout << v << endl;
	}
}