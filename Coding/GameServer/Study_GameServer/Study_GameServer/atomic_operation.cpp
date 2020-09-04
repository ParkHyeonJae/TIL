#include <iostream>
#include <memory>
#include <mutex>
#include <Windows.h>

int main(int* argv, char argc) {
	
	volatile int a = 0;
	a = 1;
	a = 2;
	a = 3;
	
	
	return 0;
}