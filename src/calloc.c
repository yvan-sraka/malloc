#include "memset.h"
#include "malloc.h"
#include "calloc.h"

void *calloc(size_t number, size_t size)
{
    void *ptr = malloc(size * number);
    my_memset(ptr, 0, size * number);
    return ptr;
}
