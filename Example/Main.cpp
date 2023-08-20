#include <cassert>
#include <iostream>
#include <sys/mman.h>

#include "ForceWrite.hpp"

int main()
{
	int* myInteger = (int*)mmap(nullptr, sizeof(int), PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	std::cout << "Allocated memory at " << std::hex << myInteger << std::dec << std::endl;

	ForceWrite::write(myInteger, 123);

	std::cout << "After writing: " << *myInteger << std::endl;

	assert(*myInteger == 123);

	std::cout << "I'm going to crash now!" << std::endl;

	*myInteger = 456;

	return 0;
}
