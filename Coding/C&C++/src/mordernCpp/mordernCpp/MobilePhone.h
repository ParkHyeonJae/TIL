//#pragma once
#include <iostream>

/*
#ifndef �� #ifdef �� ������
#ifndef �� ���� ����� ���ǵǾ����� ������ ����Ǵ� ���̰�, 
#ifdef �� �̹� ���ǰ� �Ǿ��� �� ������ �ȴ�.
���������δ� #ifdef�� ���� ������ �ʴ´ٰ� �Ѵ�.

#ifndef�� �̿��ؼ� �ش������� �ߺ� ������ ���� �� �� �ִ�.
�̹� ���ǵǾ����� ���� �� #define���� ���Ǹ� ���ֱ� ������ �ι�°���ʹ�
�Ʒ��� ������ �ι� ������� �ʴ´�.

������ �� ����� ���� ����̸�, ����� #pragma once�� �Է����ָ� �ȴ�.

*/
#ifndef MOBILE_PHONE		// <- #pragma once�� ���� ����
#define MOBILE_PHONE
class MobilePhone
{
public:
	MobilePhone(std::string productCompanyName, std::string modelName, int price)
		: productCompanyName(std::move(productCompanyName)),
		modelName(std::move(modelName)), price(price) {};
	MobilePhone(const MobilePhone& other) 
		: productCompanyName(other.productCompanyName),
		modelName(other.modelName), price(other.price) {};
	MobilePhone(MobilePhone&& other) noexcept
		: productCompanyName(std::move(other.productCompanyName)),
		modelName(std::move(other.modelName)), price(other.price) {};

	void SetModel(const std::string&);
	void SetModel(const char *);

	void PrintInfo() const;
private:
	std::string productCompanyName;
	std::string modelName;
	int price;

};
#endif // !MOBILE_PHONE