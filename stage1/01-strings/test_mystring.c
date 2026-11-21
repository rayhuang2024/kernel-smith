/* Tiny test harness: no framework, just CHECK and a failure count. */
#include <stdio.h>
#include <string.h>
#include "mystring.h"

static int failures = 0;
static int checks = 0;

#define CHECK(cond) do { \
    checks++; \
    if (!(cond)) { failures++; \
        fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); } \
} while (0)

static void test_strlen(void)
{
    CHECK(my_strlen("") == 0);
    CHECK(my_strlen("a") == 1);
    CHECK(my_strlen("hello") == 5);
    CHECK(my_strlen("embedded\0nul") == 8);
}

static void test_strcpy(void)
{
    char buf[16];
    memset(buf, 'X', sizeof buf);
    CHECK(my_strcpy(buf, "hi") == buf);           /* returns dst */
    CHECK(strcmp(buf, "hi") == 0);                /* copied + terminated */
    CHECK(buf[3] == 'X');                         /* wrote nothing past the NUL */
    CHECK(my_strcpy(buf, "")[0] == '\0');         /* empty string */
}

static void test_memcpy(void)
{
    unsigned char src[8] = {0, 1, 2, 3, 250, 251, 252, 255};
    unsigned char dst[8] = {0};
    CHECK(my_memcpy(dst, src, 8) == dst);
    CHECK(memcmp(dst, src, 8) == 0);
    unsigned char one = 7;
    CHECK(my_memcpy(&one, src, 0) == &one && one == 7); /* n == 0 is a no-op */
}

static void test_memmove(void)
{
    char a[] = "abcdefgh";
    my_memmove(a + 2, a, 5);          /* dst after src, overlapping */
    CHECK(strcmp(a, "ababcdeh") == 0);

    char b[] = "abcdefgh";
    my_memmove(b, b + 2, 5);          /* dst before src, overlapping */
    CHECK(strcmp(b, "cdefgfgh") == 0);

    char c[] = "abc";
    CHECK(my_memmove(c, c, 3) == c && strcmp(c, "abc") == 0); /* same region */
}

int main(void)
{
    test_strlen();
    test_strcpy();
    test_memcpy();
    test_memmove();
    printf("%d/%d checks passed\n", checks - failures, checks);
    return failures ? 1 : 0;
}
