#include <iostream>
#include <memory>
#include <stddef.h>

struct Resource {
	Resource() { std::cout << "Resource object created!" << std::endl; }
	~Resource() { std::cout << "Resource object destroyed!" << std::endl; }
};

int main()
{
	//If ws use new/delete, the programmer manages the lifetime
	Resource* r1 = new Resource();

	// Free the Resource
	delete r1;

	// If ws use this, they get freed automatically when the point goes out of scope
	std::unique_ptr<Resource> r2(new Resource);

	return 0;
}