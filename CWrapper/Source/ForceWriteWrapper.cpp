#include "ForceWrite.hpp"
#include "ForceWrite.h"

#include <new>

using namespace ForceWrite;

extern "C" {

const size_t forcewrite_sizeof_writer = sizeof(Writer);

void forcewrite_construct_writer(void* writer) {
	new (writer) Writer{};
}

void forcewrite_writer_write(const void* writer, void* ptr, const void* bytes, size_t length) {
	static_cast<const Writer*>(writer)->write(ptr, bytes, length);
}

void forcewrite_writer_cleanup(void* writer) {
	static_cast<Writer*>(writer)->Writer::~Writer();
}

}
