#include <iostream>
#include <vector>
#include <map>
#include <numeric>

std::vector<int> vec()
{
	return { 3,2,2 };
}

void Foo(const std::vector<int>& v) {
	std::cout << std::accumulate(v.begin(), v.end(), 0) << "\n";
}

class Vector3
{
public:

	Vector3(std::initializer_list<int> list)
	{
		auto iter = list.begin();
		x = *iter;
		y = *(iter + 1);
		z = *(iter + 2);
	}

	Vector3() = default;

	void Print() const
	{
		std::cout << "X : " << x 
			<< ", Y : " << y 
			<< ", Z : " << z << "\n";
	} 
private:
	int x, y, z;
};

int main(void)
{
	// Initalizer List
	// High Priority Initalizer List
	std::vector<int> v = { 1,2,3 };

	Foo({ 2,2,2,2,2,2,2,2,2,2 });


	std::map<std::string, int> mapTest = { {"Apple",123 }, {"Samsung", 345} ,{"ETC..", 678} };
	for (auto& iter : mapTest)
	{
		std::cout << iter.first << " : " << iter.second << "\n";
	}

	Vector3 vec = { 1,2,3 };
	vec.Print();

	int arr[3] = { 5,6,7 };
	for (auto& iter : arr)
	{
		std::cout << iter << "\n";
	}
	return 0;
}