#include <alloca.h>
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <sys/mman.h>

#include "ForceWrite.h"

int main()
{
	void* writer = alloca(forcewrite_sizeof_writer);
	forcewrite_construct_writer(writer);

	int* myInteger = (int*)mmap(NULL, sizeof(int), PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	printf("Allocated memory at %p\n", myInteger);

	printf("Before writing: %d\n", *myInteger);

	int newInteger = 123;
	forcewrite_writer_write(writer, myInteger, &newInteger, sizeof(int));

	printf("After writing: %d\n", *myInteger);

	assert(*myInteger == 123);

	forcewrite_writer_cleanup(writer);

	return 0;
}
