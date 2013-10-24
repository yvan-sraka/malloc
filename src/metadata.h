#ifndef METADATA_H
# define METADATA_H
# define PAGE_SIZE getpagesize()
# define BLOCK_SIZE sizeof (struct s_block)
# define ALIGN_8(x) (((((x)-1)>>3)<<3)+8)

#include <unistd.h>

typedef struct s_block
{
    size_t size;
    size_t is_free;
    struct s_block *prev;
    struct s_block *next;
} s_block;

char* vtoc(void *v);
void* atov(void *a);

#endif /* !METADATA_H */
