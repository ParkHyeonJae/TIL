#include "MobilePhone.h"


void MobilePhone::PrintInfo() const
{
	std::cout << "ProductCompany : " << productCompanyName
		<< ", Model : " << modelName << ", Price : " << price << std::endl;
}

void MobilePhone::SetModel(const std::string& modelName)
{
	this->modelName = modelName;
}

void MobilePhone::SetModel(const char* modelName)
{
	this->modelName = modelName;
}
