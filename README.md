# malloc #

This library implement C dynamic memory allocation functions.
It use first fit algorithm with a looped double chained list of blocks.

[![Build Status](https://travis-ci.com/yvan-sraka/malloc.svg?token=r9S39DVzZNKVuhr9yRC6&branch=master)](https://travis-ci.com/yvan-sraka/malloc)

Memory allocator:
``` C
void* malloc(size_t size);
```

Free allocated memory:
``` C
void free(void *ptr);
```

Allocate and initialize memory:
``` C
void* calloc(size_t number, size_t size);
```

Change space of allocated memory:
``` C
void* realloc(void *ptr, size_t size);
```
