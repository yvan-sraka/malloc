#include "malloc.h"
#include "memcpy.h"
#include "free.h"
#include "realloc.h"

void* realloc(void *ptr, size_t size)
{
    if (!ptr)
        return NULL;
    s_block *b = atov(vtoc(ptr) - BLOCK_SIZE);
    size_t s = ALIGN_8(size) + BLOCK_SIZE;
    if (b && b->next && b->next->is_free && b->next->size > (s - b->size))
    {
        s_block *new = atov(vtoc(b) + s);
        new->size = b->size + b->next->size - s;
        b->next->next->prev = new;
        new->next = b->next->next;
        new->prev = b;
        b->next = new;
        b->size = s;
        new->is_free= 1;
        return ptr;
    }
    else
    {
        void *p = malloc(size);
        memcpy(p, ptr, b->size);
        free(ptr);
        return p;
    }
}
