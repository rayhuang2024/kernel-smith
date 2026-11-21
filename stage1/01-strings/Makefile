CC      ?= gcc
CFLAGS  ?= -std=c11 -Wall -Wextra -Werror -pedantic -g -O0
ASAN    := -fsanitize=address,undefined -fno-omit-frame-pointer

all: test_mystring

test_mystring: test_mystring.c mystring.c mystring.h
	$(CC) $(CFLAGS) -o $@ test_mystring.c mystring.c

test_mystring_asan: test_mystring.c mystring.c mystring.h
	$(CC) $(CFLAGS) $(ASAN) -o $@ test_mystring.c mystring.c

test: test_mystring
	./test_mystring

asan: test_mystring_asan
	./test_mystring_asan

valgrind: test_mystring
	valgrind --error-exitcode=1 --leak-check=full -q ./test_mystring

clean:
	rm -f test_mystring test_mystring_asan

.PHONY: all test asan valgrind clean
