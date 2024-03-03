#include "ForceWrite.hpp"

#include <fcntl.h>
#include <unistd.h>

using namespace ForceWrite;

Writer::Writer()
	: fd(open("/proc/self/mem", O_WRONLY))
{
}

Writer::~Writer()
{
	close(fd);
}

void Writer::write(void* ptr, const void* bytes, std::size_t length) const
{
	pwrite(fd, bytes, length, reinterpret_cast<off_t>(ptr));
}