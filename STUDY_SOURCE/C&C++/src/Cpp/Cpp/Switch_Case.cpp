#include <iostream>


int main(void)
{
	/*
	Switch Case ������ ���� ����
	
	switch (x) {
	case 1:
		break;
	case 2:
		std::cout << "2" << "\n";
		[[__fallthrough]]
	case 3:
		std::cout << "3" << "\n";
		break;
	default:
		break;
	}

	���������� ������ �̷���
	
	if(x <= 3)		// 3���� ���� ���
	{
		code = jumpTable[x];		// ���� ���̺��� �ڵ带 �����´�.
		goto code;			// �ش� �ڵ尡 ��ġ�� ������ �̵��Ѵ�.
	}
	else{ goto default; }		// 3���� ���� ���� ��쿡�� default�� �̵��Ѵ�.

	�̷������� �������̺��� �ش�Ǵ� �ּҸ� �����ͼ� �ش� �ּҷ� ������ �����ִ�
	������ �Ǿ������� break;���� ���� �ȴٸ� ret��� opcode�� �۵��ϰ� �Ǹ鼭 �Լ��� �ٷ� 
	���������� �ȴ�.
	������ break;�� ���� switch������ �ٷ� ���������� �Ǹ�, ���� break;�� ���� �ʰԵǸ�
	ret �̶�� opcode�� ������ ���� �ʱ⶧���� �ٷ� ���� ������ �̵��� �ǰ� �ȴ�.

	���� �������� ������ ó���� �Ϸ��� break;�� �����ָ� �Ǳ� �ѵ�, �̷��� 
	��� �޽����� �� ���ɼ��� �ֱ⶧���� [[__fallthrough]]�� ����Ѵ�.
	*/

	switch (2) {
	case 1:
		break;
	case 2:
		std::cout << "2" << "\n";
		[[__fallthrough]]
	case 3:
		std::cout << "3" << "\n";
		break;
	default:
		break;
	}
	

	return 0;
}