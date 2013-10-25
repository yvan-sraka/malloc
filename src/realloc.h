#ifndef REALLOC_H
# define REALLOC_H

void* realloc(void *ptr, size_t size);
void move_block(s_block *b, size_t s);

#endif /* !REALLOC_H */
