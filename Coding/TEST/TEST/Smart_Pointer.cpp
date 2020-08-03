#include <iostream>
#include <memory>

using namespace std;

class SimpleCat
{
public:
	SimpleCat();			// Constructor
	SimpleCat(SimpleCat& simplecat);		//Copy constructor
	~SimpleCat();		//destructor
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
};
SimpleCat::SimpleCat() : itsAge(1)
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
const SimpleCat* const FunctionTwo(const SimpleCat*const theCat);
int main()
{
	cout << "Making a cat..\n";
	SimpleCat Frisky;
	cout << "Frisky is ";
	cout << Frisky.GetAge();
	cout << " years old\n";
	cout << "-------------------\n";

	int age = 5;
	Frisky.SetAge(age);
	cout << "Frisky is ";
	cout << Frisky.GetAge();
	cout << " year old\n";
	cout << "-------------------\n";
	cout << "Calling FunctionTwo..\n";
	FunctionTwo(&Frisky);
	cout << "-------------------\n";
	cout << "Frisky is ";
	cout << Frisky.GetAge();
	cout << " years old\n";


	return 0;
}
// FunctionTwo, passes by reference
const SimpleCat* const  FunctionTwo(const SimpleCat*const theCat)
{
	cout << "Function Two. Returning..\n";
	cout << "Frisky is now " << theCat->GetAge();
	cout << " years old \n";
	// theCat->SetAge(6); const !
	return theCat;
}
