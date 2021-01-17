#include <iostream>
namespace header2 {
	void foo(void);
	void foo(void) { std::cout << "header2" << std::endl; }

	void func() {

	}

}
namespace header1 {
	void foo(void) { std::cout << "header1" << std::endl; }

	void func() {
		foo();
		header2::foo();
	}
	
}

// 현재 파일 안에서만 접근이 가능하고 다른파일에서는 접근이 불가능하다
// static 키워드를 사용한 것과 같은 효과
namespace {

	void OnlyInThisFile() {}

	int only_in_this_file = 0;
}

using header1::foo;

int main(void)
{
	header1::func();
	OnlyInThisFile();
	only_in_this_file = 10;
	return 0;
}