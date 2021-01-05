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
	
	//RAII (Resource Acquisition is initialization) : Resource 와 Object Life cycle을 sync 시킨다.
	// Exclusive Ownership
	std::unique_ptr<VRDevice> device04 = std::make_unique<VRDevice>(*device03);
	device04->SetDevice("Oculus Quest 1");
	device04->PrintInfo();

	/*
	std::unique_ptr<VRDevice> device05 = device04; <- Error

	기존의 unique_ptr 형태는 Exclusive Ownership으로 
	인해서 소유권 관련해서 copy가 이루어지려고 하면 
	에러가 발생한다.

	따라서 shared_ptr이 이를 가능하게 한다

	일반적인 copy를 통한 이동은 에러를 발생시키지만,
	move를 통한 R-VALUE PASS 를 통하면 에러를 발생시키지 않는다.
	move가 원래 있던 포인터에 소유권 그 자체를 양도해주기 때문
	*/
	
	std::unique_ptr<VRDevice> device05 = std::move(device04);
	device05->SetDevice("Oculus Quest 2 256GB");
	device05->PrintInfo();
	delete device03;
	return 0;
}