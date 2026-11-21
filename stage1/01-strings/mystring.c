#include "mystring.h"

/* TODO: replace each stub with a real implementation.
 * Rules for yourself: no calls to <string.h>, no array indexing in
 * my_memcpy/my_memmove (use pointers), and think about n == 0. */

size_t my_strlen(const char *s)
{
    (void)s;
    return 0; /* TODO */
}

char *my_strcpy(char *dst, const char *src)
{
    (void)src;
    return dst; /* TODO */
}

void *my_memcpy(void *dst, const void *src, size_t n)
{
    (void)src; (void)n;
    return dst; /* TODO */
}

void *my_memmove(void *dst, const void *src, size_t n)
{
    /* Hint: if dst is after src and they overlap, copy backwards. */
    (void)src; (void)n;
    return dst; /* TODO */
}
