#ifndef MALLOC_H
# define MALLOC_H

# define _GNU_SOURCE

# include <sys/mman.h>
# include <errno.h>
# include <string.h> /* memset */
# include <unistd.h> /* close */

# include "metadata.h"

void *malloc(size_t size);
s_block *new_block(size_t s);
s_block *find_block(size_t s);
void split_block(s_block *b, size_t s);

#endif /* !MALLOC_H */
