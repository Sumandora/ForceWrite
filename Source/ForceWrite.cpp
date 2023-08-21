#include "ForceWrite.hpp"

void ForceWrite::write(void* ptr, const char* bytes, std::size_t length)
{
	if (procMem == nullptr)
		procMem = std::make_unique<ProcMem>();

#ifdef __x86_64
	pwrite64(procMem->fd, bytes, length, reinterpret_cast<off_t>(ptr));
#else
	pwrite(procMem->fd, bytes, length, reinterpret_cast<off_t>(ptr));
#endif
}