#include <iostream>

class AAA
{
public:
	static int b;
};
int AAA::b = 99;		// C++ 17 ���������� ����� static�� �������ָ� ������ ���Ǹ� ����� ����.

/// <summary>
/// static Ű���带 ���̰� �Ǹ� internal linkage��� �ǹ̸� ���⵵ ������ ���ÿ� 
/// �޸��� data ������ ���� �Ǹ鼭 ���� Ŭ������ �����ϰ� �Ǿ ��������� �ִ� static int b�� �ϳ��� �����ν� ���� �� �ְ� �ȴ�.
/// 
/// �̴� ������ Ÿ�ӿ� static int b�� data ������ �־ ���߿� �̸� ����ϰ� �Ǹ� load time���� �̸� �����ٰ� ����ϰ� �ȴ�.
/// </summary>

static int a = 20;

int main(void)
{
	AAA a1;
	AAA a2;
	AAA a3;

	a1.b = 20;

	std::cout << a3.b;

	return 0;
}