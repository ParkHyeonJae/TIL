#include <memory>
#include <iostream>

class VRDevice
{
public:
	VRDevice(std::string deviceName, std::string productFirm, int price)
			: deviceName(std::move(deviceName)), productFirm(std::move(productFirm)), price(price) {}

	VRDevice(VRDevice& other)
		: deviceName(std::move(other.deviceName)), productFirm(std::move(other.productFirm)), price(other.price) {}

	VRDevice(VRDevice&& other) noexcept
		: deviceName(std::move(other.deviceName)), productFirm(std::move(other.productFirm)), price(other.price) {}

	void SetDevice(std::string deviceName);
	void PrintInfo();
private:
	std::string deviceName;
	std::string productFirm;
	int price;
};
void VRDevice::SetDevice(std::string deviceName)
{
	this->deviceName = std::move(deviceName);
}

void VRDevice::PrintInfo()
{
	std::cout << "Device Name : " << deviceName << ", Product Firm : " << productFirm << ", Price : " << price << std::endl;
}

int main()
{
	// Stack

	VRDevice device01{ "Oculus Quest", "Oculus", 410000 };
	device01.PrintInfo();
	VRDevice device02 = std::move(device01);
	device02.SetDevice("Oculus Quest 2");
	device02.PrintInfo();

	// Heap

	VRDevice* device03 = new VRDevice(std::move(device02));
	device03->PrintInfo();
	
	//RAII (Resource Acquisition is initialization) : Resource �� Object Life cycle�� sync ��Ų��.
	// Exclusive Ownership
	std::unique_ptr<VRDevice> device04 = std::make_unique<VRDevice>(*device03);
	device04->SetDevice("Oculus Quest 1");
	device04->PrintInfo();

	/*
	std::unique_ptr<VRDevice> device05 = device04; <- Error

	������ unique_ptr ���´� Exclusive Ownership���� 
	���ؼ� ������ �����ؼ� copy�� �̷�������� �ϸ� 
	������ �߻��Ѵ�.

	���� shared_ptr�� �̸� �����ϰ� �Ѵ�

	�Ϲ����� copy�� ���� �̵��� ������ �߻���Ű����,
	move�� ���� R-VALUE PASS �� ���ϸ� ������ �߻���Ű�� �ʴ´�.
	move�� ���� �ִ� �����Ϳ� ������ �� ��ü�� �絵���ֱ� ����
	*/
	
	std::unique_ptr<VRDevice> device05 = std::move(device04);
	device05->SetDevice("Oculus Quest 2 256GB");
	device05->PrintInfo();
	delete device03;
	return 0;
}