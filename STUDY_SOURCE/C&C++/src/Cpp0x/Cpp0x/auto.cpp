#include <vector>

std::vector<int> v;


std::vector<int>::iterator iter = v.begin();
// �������� ���� ���� �� ���¿� ���缭 Ÿ���� ������� ������

// C++0x������ auto Ű���带 ���ؼ� ������ Ÿ�ӿ� �����Ϸ��� ���¸� �Ǵܽ����ش�.
auto auto_iter = v.begin();

// *,&,const,volatile� ����

int main(void)
{
	return 0;
}