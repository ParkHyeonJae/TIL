#include <iostream>
#include <memory>

using namespace std;

class SimpleCat
{
public:
	SimpleCat();			// Constructor
	SimpleCat(SimpleCat& simplecat);		//Copy constructor
	~SimpleCat();		//destructor
};
SimpleCat::SimpleCat()
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
SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat* FunctionTwo(SimpleCat* theCat);
int main()
{
	cout << "Making a cat...\n";
	SimpleCat frisky;
	cout << "Calling FunctionOne.. \n";
	FunctionOne(frisky);
	cout << "Calling FunctionTwo...\n";
	FunctionTwo(&frisky);

	return 0;
}
// FunctionOne, passes by value
SimpleCat FunctionOne(SimpleCat theCat)
{
	cout << "Function One. Returning..\n";
	return theCat;
}

// FunctionTwo, passes by reference
SimpleCat* FunctionTwo(SimpleCat* theCat)
{
	cout << "Function Two. Returning..\n";
	return theCat;
}
