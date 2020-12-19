//#pragma once
#include <iostream>

/*
#ifndef 와 #ifdef 의 차이점
#ifndef 은 만약 대상이 정의되어있지 않으면 실행되는 것이고, 
#ifdef 은 이미 정의가 되었을 시 실행이 된다.
실질적으로는 #ifdef는 별로 쓰이지 않는다고 한다.

#ifndef를 이용해서 해더파일의 중복 선언을 방지 할 수 있다.
이미 정의되어있지 않을 시 #define으로 정의를 해주기 때문에 두번째부터는
아래의 내용이 두번 실행되지 않는다.

하지만 이 방식은 옛날 방식이며, 현재는 #pragma once만 입력해주면 된다.

*/
#ifndef MOBILE_PHONE		// <- #pragma once와 같은 역할
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