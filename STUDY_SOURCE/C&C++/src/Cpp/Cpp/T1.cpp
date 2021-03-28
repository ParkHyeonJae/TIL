#include <iostream>

/*
������ ���μ����� �̷���.
���� �� cpp���ϵ�� ���(.h)���ϵ��� #include�� ���ؼ� �ϳ��� ���ս��������ν� Translation Unit�� ����� �ǰ� �̵��� ������Ʈ(.o)���Ϸ� �����Ϸ��� �ٲ��ְ�, �̷��� ������Ʈ ���ϵ���
��Ŀ�� ��ŷ�� ���ָ鼭 �ϳ��� excutable(exe)���Ϸ� ��ȯ�� �����ִ� ���μ����̴�.

�̶� ������Ʈ ���ϵ��� ��Ŀ�� ��ŷ�� ���ִ� �������� Global Variable�� ������ ���� int a �� �����ϸ� �̴� �浹�� �Ͼ�� �ȴ�. (Error	LNK2005	"int a" (?a@@3HA) already defined in T1.obj	Cpp)

���� �̸� Global Variable�� internal���� external���� ��� �������ֳĿ� ���� linkage�� ������ �޶�����.
���� extern int a; �� ���ؼ� external linkage�� ���� �Ͽ��� ��, �̴� �ܺ��� Translation Unit�� ���ǵǾ� �ִ� a�� �����ͼ� ���ڴٰ� �˷��ְ� �Ǹ鼭
�ܺο� int a = 20;�̶�� ���ǵǾ� �ִٸ� ��ũ ���μ����� �����ϸ鼭 ���������� a�� 20�� �ȴ�.

static Ű���带 ���� internal linkage�� ������ �ϰ� �Ǹ�, �̴� ���������� ���ǵǾ��ִ� �ϳ��� Translation Unit���θ� ����� �Ǳ� ������ �ܺο� �����ϴ� �ٸ�
Translation Unit���� ����� �� ���� �ȴ�.

���� Global Variable�� cpp�ȿ��� ����ϰ� �ȴٸ� static�� �ٿ��ְ� �ٱ����� link�� ���°��� ����.

*/

static int a;

int main(void)
{
	std::cout << a;
	return 0;
}