#include "malloc.h"

static s_block *token = NULL;

void* malloc(size_t size)
{
    if (!size)
        return NULL;
    if (!token)
        token = new_block(PAGE_SIZE);
    size_t s = ALIGN_8(size) + BLOCK_SIZE;
    s_block *b = find_block(s);
    if (!b)
        b = new_block(s);
    if (!b)
        return NULL;
    split_block(b, s);
    b->is_free = 0;
    token = b;
    return b + 1;
}

s_block* new_block(size_t s)
{
    s = ((s / PAGE_SIZE) + 1) * PAGE_SIZE;
    s_block *b = mmap(0, s, PROT_READ | PROT_WRITE, MAP_ANON, -1, 0);
    if (!b)
    {
        errno = ENOMEM;
        return NULL;
    }
    else if (!token)
    {
        b->prev = b;
        b->next = b;
    }
    else
    {
        if (token->next)
            token->next->prev = b;
        b->next = token->next;
        b->prev = token;
        token->next = b;
    }
    b->is_free = 1;
    b->size = s;
    return b;
}

s_block* find_block(size_t s)
{
    for(s_block *b = token->next; b != token; b = b->next)
        if(b->is_free && b->size >= s)
            return b;
    return NULL;
}

void split_block(s_block *b, size_t s)
{
    if (b->size > (s + BLOCK_SIZE))
    {
        s_block *new = atov(vtoc(b) + s);
        if (b->next)
            b->next->prev = new;
        new->next = b->next;
        new->prev = b;
        b->next = new;
        new->size = b->size - s;
        b->size = s;
        new->is_free = 1;
    }
}
