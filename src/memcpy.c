#include "memcpy.h"

void* memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    for (unsigned int i = 0; i < n; i++)
        d[i] = s[i];
    return d;
}
