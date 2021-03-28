#include <iostream>


int main(void)
{
	std::string str = "abc";		// 라이브러리 구현에 따라 다르지만 대게 16byte 아래의 사이즈의 문자열들은 heap이 아닌, stack에 alloc이 되기때문에 퍼포먼스면으로 좋을 수 있다.

	std::cout << sizeof(str) << std::endl;
	std::string_view sv = "abcdef";		// 임시객체를 생성하지 않고 문자열을 사용할 수 있다.
	std::cout << sv << std::endl;
	return 0;
}