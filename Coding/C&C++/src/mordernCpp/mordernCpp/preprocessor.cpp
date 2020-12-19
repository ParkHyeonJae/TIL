#include "MobilePhone.h"

int main()
{
	MobilePhone phone01{ "Samsung", "S10", 1294030 };
	phone01.PrintInfo();

	MobilePhone phone02{ "LG", "V50 ThinQ 5G",  1187010 };
	phone02.PrintInfo();

	phone01.SetModel("S10 5G");
	phone01.PrintInfo();

	return 0;
}