#include "../src/malloc.h"
#include "../src/free.h"
#include "../src/calloc.h"
#include "../src/realloc.h"

int main(void)
{
    int *ptr = malloc(13);
    ptr = realloc(ptr, 42);
    free(ptr);
    return 0;
}
