#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>

/* Week 1: implement these four in mystring.c.
 * Match the C standard library's behavior (see `man 3 strlen` etc.). */
size_t my_strlen(const char *s);
char  *my_strcpy(char *dst, const char *src);
void  *my_memcpy(void *dst, const void *src, size_t n);   /* regions must NOT overlap */
void  *my_memmove(void *dst, const void *src, size_t n);  /* regions MAY overlap */

#endif
