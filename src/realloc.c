#include "malloc.h"
#include "memcpy.h"
#include "free.h"
#include "realloc.h"

void* realloc(void *ptr, size_t size)
{
    if (!ptr)
        ptr = NULL;
    else if (!size)
        free(ptr);
    else
    {
        s_block *b = atov(vtoc(ptr) - BLOCK_SIZE);
        size_t s = ALIGN_8(size) + BLOCK_SIZE;
        if (s < b->size ||
           (b->next && b->next->is_free && b->next->size > (s - b->size)))
            move_block(b, s);
        else
        {
            void *p = malloc(size);
            memcpy(p, ptr, b->size);
            free(ptr);
            ptr = p;
        }
    }
    return ptr;
}

void move_block(s_block *b, size_t s)
{
    s_block *new = atov(vtoc(b) + s);
    new->size = b->size + b->next->size - s;
    b->next->next->prev = new;
    new->next = b->next->next;
    new->prev = b;
    b->next = new;
    b->size = s;
    new->is_free= 1;
}
