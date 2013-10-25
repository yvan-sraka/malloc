#include "memset.h"

void my_memset(void *ptr, int value, size_t size)
{
    int *integer = ptr;
    for (unsigned int i = 0; i < size; i++)
        integer[i] = value;
}
