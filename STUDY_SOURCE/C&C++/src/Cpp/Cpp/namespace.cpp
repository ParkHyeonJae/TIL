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

// ���� ���� �ȿ����� ������ �����ϰ� �ٸ����Ͽ����� ������ �Ұ����ϴ�
// static Ű���带 ����� �Ͱ� ���� ȿ��
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