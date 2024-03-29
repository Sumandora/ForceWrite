#include <cassert>
#include <iostream>
#include <sys/mman.h>

#include "ForceWrite.hpp"

int main()
{
	using namespace ForceWrite;
	Writer writer{};

	int* myInteger = (int*)mmap(nullptr, sizeof(int), PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	std::cout << "Allocated memory at " << std::hex << myInteger << std::dec << std::endl;

	std::cout << "Before writing: " << *myInteger << std::endl;

	writer.write(myInteger, 123);

	std::cout << "After writing: " << *myInteger << std::endl;

	assert(*myInteger == 123);

	return 0;
}
