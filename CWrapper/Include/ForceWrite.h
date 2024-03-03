#ifndef FORCEWRITE_H
#define FORCEWRITE_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const size_t forcewrite_sizeof_writer;

void forcewrite_construct_writer(void* writer);
void forcewrite_write(const void* writer, void* ptr, const void* bytes, size_t length);
void forcewrite_cleanup(void* writer);

#ifdef __cplusplus
}
#endif

#endif
