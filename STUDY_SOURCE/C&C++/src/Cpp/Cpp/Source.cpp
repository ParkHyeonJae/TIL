#include "Singleton.hpp"
#include <iostream>

class Helper : public Singleton<Helper>
{
public:
	int Get()
	{
		return 20;
	}
};


int main(void)
{
	std::cout << Helper::getInstance().Get();

	return 0;
}