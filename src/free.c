#include "metadata.h"
#include "free.h"

void free(void *ptr)
{
    if (ptr)
    {
        s_block *b = atov(vtoc(ptr) - BLOCK_SIZE);
        b->is_free = 1;
        if (b->prev && b->prev->is_free)
            fusion_blocks(b->prev, b);
        if (b->next && b->next->is_free)
            fusion_blocks(b, b->next);
    }
}

void fusion_blocks(s_block *b1, s_block *b2)
{
    if (atov(vtoc(b1) + b1->size) == b2)
    {
        b1->next = b2->next;
        if (b1->next)
            b1->next->prev = b1;
        b1->size += b2->size;
    }
}
