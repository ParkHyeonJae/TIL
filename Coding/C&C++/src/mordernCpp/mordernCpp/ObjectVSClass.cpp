#include <iostream>

class MobilePhone
{
public:
	MobilePhone(const std::string& name) : name(name) {}
private:
	std::string name;
};

int main()
{
	// Object �� Class �� ������
	MobilePhone phone01("S10");		// MobilePhone �� Class, Object�� ������ Phone01�� ����Ŵ

	/*
	Object ���� �� ������ ��
	JAVA ������ �ؼ̴� ��������ϸ� �翬�ϰԵ� ��ü�� ����� ��
	MobilePhone * phone02 = new MobilePhone("S10");
	�Ʒ��� ���� new Ű���带 ���ؼ� ���� �Ҵ� �ް� ����� �ϼż�
	C++ ������ ���� �̷������� �ַ� ����ϴ� ��쵵 �ִ�.

	������ C++ �� ������ JAVA�� �� �ٸ����� �ֱ⿡ new�� �� ��ü�� ����� ������ ����ؼ��� �ȵȴ�.

	C++ ������ ������ ������ new�� ����ϰ� �Ǹ� Heap�� �޸� �ּҰ� ����� �ȴ�.
	Heap�� ����� ������ �ݵ�� delete ������� �� �Ѵ�.

	Object�� Instance�� �������� ��������� ���� ���� �� ��� ��� ����� �ǹ��ΰ� ����.
	�ϴ� C++ �ʿ����� Instnace���ٴ� Object�� �� ���� ����ϴ� �� ����, Instance�� �ַ� �̱������� ������ Ư���� ����� �� �θ��� �� ����.

	JAVA������
	MobilePhone phone01;
	phone01 = new MobilePhone();
	�̷� �ڵ尡 ���� ��,
	MobilePhone�� class�̸�, 
	phone01�� object,
	phone01 = new MobilePhone()�� �޾��� �� Instance��� �θ��� �� ����.
	*/
	
	return 0;
}