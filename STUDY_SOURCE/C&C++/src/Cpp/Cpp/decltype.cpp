#include <iostream>

template<typename T, typename U>
auto sum(T v1, U v2) -> decltype(v1 + v2)
{
	return v1 + v2;
}

int main(void)
{
	sum(std::string("Hello"), std::string("There"));

	return 0;
}