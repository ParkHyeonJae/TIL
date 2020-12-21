#include <iostream>
#include <memory>

using namespace std;

class SimpleCat
{
public:
	SimpleCat(int age, int weight);			// Constructor
	SimpleCat(SimpleCat& simplecat);		//Copy constructor
	~SimpleCat();		//destructor
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
	int itsWeight;
};
SimpleCat::SimpleCat(int age, int weight) : itsAge(age), itsWeight(weight)
{
	cout << "Simple Cat Constructor..\n";
}
SimpleCat::SimpleCat(SimpleCat& simplecat)
{
	cout << "Simple Cat Copy Constructor...\n";
}
SimpleCat::~SimpleCat()
{
	cout << "Simple Cat Destructor..\n";
}

shared_ptr<SimpleCat> TheFunction();

int main()
{
	auto rCat = TheFunction();
	auto rat02 = rCat;
	int age = rCat->GetAge();
	cout << "rCat is " << age << " years old\n";
	return 0;
}


shared_ptr<SimpleCat> TheFunction()
{
	
	shared_ptr<SimpleCat> frisky = make_shared<SimpleCat>(5, 9);
	cout << "frisky is " << frisky->GetAge() << " years old\n";
	return frisky;
	
}