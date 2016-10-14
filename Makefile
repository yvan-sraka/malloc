CC=gcc

SRC=$(addprefix src/, malloc.c free.c calloc.c realloc.c metadata.c memset.c memcpy.c)
OBJ=$(SRC:.c=.o)

CFLAGS=-Wall -Werror -Wextra -std=c99 -pedantic -O2 -ggdb3
ARFLAGS=csr
SOFLAGS=-shared -fPIC -o
OFLAGS=-c -fPIC

LIBA=libmalloc.a
LIBSO=libmalloc.so

EXPORTAG=HEAD --prefix=sraka_y-malloc/ | bzip2
EXPORTFILE=sraka_y-malloc.tar.bz2

all:$(OBJ)
	ar $(ARFLAGS) $(LIBA) $^
	$(CC) $(SOFLAGS) $(LIBSO) $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $(OFLAGS) $<

clean:
	rm -rf $(OBJ) $(LIBA) $(LIBSO)
.PHONY: clean


check: all
	$(CC) check/main.c -lmalloc -L. $(CFLAGS) $(OBJ)
.PHONY: check

test: check

export:
	git archive $(EXPORTAG) > $(EXPORTFILE)
