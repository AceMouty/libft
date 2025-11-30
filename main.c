#include "check.h"
#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_memcmp_test();
void ft_strnstr_test();
void ft_atoi_test();
char *strnstr(const char *big, const char *small, size_t len);

int main(void) {
  char src[] = "coucou";
  char dest[10];

  printf("===================================\n");
  printf("ft_strlcpy\n");
  printf("===================================\n");
  memset(dest, 'A', 10);

  /* 1 */ check(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A');

  /* 2 */ check(ft_strlcpy(dest, src, 1) == strlen(src) && dest[0] == 0 &&
                dest[1] == 'A');

  /* 3 */ check(ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' &&
                dest[1] == 0 && dest[2] == 'A');

  /* 4 */ check(ft_strlcpy(dest, src, -1) == strlen(src) &&
                !strcmp(src, dest) && dest[strlen(src) + 1] == 'A');

  memset(dest, 'A', 10);
  /* 5 */ check(ft_strlcpy(dest, src, 6) == strlen(src) &&
                !memcmp(src, dest, 5) && dest[5] == 0);

  memset(dest, 'A', 10);
  /* 6 */ check(ft_strlcpy(dest, src, 7) == strlen(src) &&
                !memcmp(src, dest, 7));

  memset(dest, 'A', 10);
  /* 7 */ check(ft_strlcpy(dest, src, 8) == strlen(src) &&
                !memcmp(src, dest, 7));

  memset(dest, 'A', 10);
  /* 8 */ check(ft_strlcpy(dest, "", 42) == 0 && !memcmp("", dest, 1));

  memset(dest, 0, 10);
  /* 9 */ check(ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0);

  memset(dest, 'A', 10);

  printf("===================================\n");
  printf("ft_strlcat\n");
  printf("===================================\n");

  int res;
  int expected;
  /* set src and dest initial content */
  memset(dest, 'A', 10);
  dest[0] = 0; /* so dest="" initially */

  /* 1: size = 0 → nothing appended, return strlen(src) */
  // dest = "", src = "coucou"
  res = ft_strlcat(dest, src, 0);
  expected = strlen(src);
  check(res == expected && dest[0] == 0);

  memset(dest, 'A', 10);
  dest[0] = 0;

  /* 2: size = 1 → can only NUL-terminate; return strlen(src) */
  res = ft_strlcat(dest, src, 1);
  expected = strlen(src);
  check(res == expected && dest[0] == 0 && dest[1] == 'A');

  memset(dest, 'A', 10);
  strcpy(dest, "c");

  /* 3: size = 2 → dest="c"; room for 1 byte + NUL */
  /* result should be "c" + first char of src */
  res = ft_strlcat(dest, src, 2);
  expected = 1 + strlen(src);
  check(res == expected && dest[0] == 'c' && dest[1] == '\0');

  memset(dest, 'A', 10);
  strcpy(dest, "c");

  /* 4: size = -1 → effectively huge; full concat */
  /* dest becomes "c" + src entirely */
  check(ft_strlcat(dest, src, (size_t)-1) == 1 + strlen(src) &&
        !strcmp(dest, (char[]){'c', 0}) + !strcmp(dest + 1, src) &&
        dest[1 + strlen(src) + 1] == 'A');

  memset(dest, 'A', 10);
  strcpy(dest, "Hello");

  /* 5: size = 6 → dest="Hello" (len=5), room for 0 chars + NUL */
  check(ft_strlcat(dest, src, 6) == 5 + strlen(src) &&
        !memcmp(dest, "Hello", 6) && /* unchanged except NUL */
        dest[5] == 0);

  memset(dest, 'A', 10);
  strcpy(dest, "Hello");

  /* 6: size = 7 → dest len=5, room for 1 char + NUL */
  check(ft_strlcat(dest, src, 7) == 5 + strlen(src) &&
        !memcmp(dest, "Hello", 5) && dest[5] == src[0]);

  memset(dest, 'A', 10);
  strcpy(dest, "Hello");

  /* 7: size = 8 → room for 2 chars + NUL */
  check(ft_strlcat(dest, src, 8) == 5 + strlen(src) &&
        !memcmp(dest, "Hello", 5) && !memcmp(dest + 5, src, 2));

  memset(dest, 'A', 10);
  dest[0] = 0;

  /* 8: src="" → no change, return len(dest)=0 */
  check(ft_strlcat(dest, "", 42) == 0 && !memcmp(dest, "", 1));

  memset(dest, 0, 10);
  strcpy(dest, "1");

  /* 9: size = 0 → return size + strlen(src) = 0 + 1; no change */
  res = ft_strlcat(dest, src, 0);
  expected = strlen(src);
  check(res == expected && dest[0] == '1');

  memset(dest, 'A', 10);

  printf("===================================\n");
  printf("ft_toupper\n");
  printf("===================================\n");

  /* 1 */ check(ft_toupper('a') == toupper('a'));
  /* 2 */ check(ft_toupper('z') == toupper('z'));
  /* 3 */ check(ft_toupper('m') == toupper('m'));
  /* 4 */ check(ft_toupper('A') == toupper('A'));
  /* 5 */ check(ft_toupper('Z') == toupper('Z'));
  /* 6 */ check(ft_toupper('0') == toupper('0'));
  /* 7 */ check(ft_toupper('!') == toupper('!'));
  /* 8 */ check(ft_toupper(' ') == toupper(' '));
  /* 9 */ check(ft_toupper(EOF) == toupper(EOF));

  printf("===================================\n");
  printf("ft_tolower\n");
  printf("===================================\n");
  /* 1: uppercase 'A' → 'a' */
  check(ft_tolower('A') == tolower('A'));
  /* 2: uppercase 'Z' → 'z' */
  check(ft_tolower('Z') == tolower('Z'));
  /* 3: uppercase 'M' → 'm' */
  check(ft_tolower('M') == tolower('M'));
  /* 4: lowercase 'a' stays 'a' */
  check(ft_tolower('a') == tolower('a'));
  /* 5: lowercase 'z' stays 'z' */
  check(ft_tolower('z') == tolower('z'));
  /* 6: digit '0' unchanged */
  check(ft_tolower('0') == tolower('0'));
  /* 7: punctuation '!' unchanged */
  check(ft_tolower('!') == tolower('!'));
  /* 8: space ' ' unchanged */
  check(ft_tolower(' ') == tolower(' '));
  /* 9: EOF must be returned unchanged */
  check(ft_tolower(EOF) == tolower(EOF));

  printf("===================================\n");
  printf("ft_strchr\n");
  printf("===================================\n");
  char s1[] = "hello";
  char s2[] = "abcabc";
  char s3[] = "";
  char s4[] = "end?";
  char s5[] = "null\0inside"; // just to make intent clear

  /* 1: char at beginning */
  /* "hello" -> 'h' at index 0 */
  /* 1 */ check(ft_strchr(s1, 'h') == strchr(s1, 'h'));

  /* 2: char in the middle */
  /* "hello" -> 'l' first at index 2 */
  /* 2 */ check(ft_strchr(s1, 'l') == strchr(s1, 'l'));

  /* 3: char at the end */
  /* "end?" -> '?' at last position */
  /* 3 */ check(ft_strchr(s4, '?') == strchr(s4, '?'));

  /* 4: char not present at all */
  /* "hello" -> 'z' not found, should return NULL */
  /* 4 */ check(ft_strchr(s1, 'z') == strchr(s1, 'z'));

  /* 5: multiple occurrences -> must return first one */
  /* "abcabc" -> 'b' at index 1, not 4 */
  /* 5 */ check(ft_strchr(s2, 'b') == strchr(s2, 'b'));

  /* 6: search for '\0' terminator */
  /* should return pointer to the terminating NUL */
  /* 6 */ check(ft_strchr(s1, '\0') == strchr(s1, '\0'));

  /* 7: empty string, search for '\0' */
  /* should return pointer to s3 (first byte, which is '\0') */
  /* 7 */ check(ft_strchr(s3, '\0') == strchr(s3, '\0'));

  /* 8: empty string, search for non-existing char */
  /* should return NULL on both */
  /* 8 */ check(ft_strchr(s3, 'x') == strchr(s3, 'x'));

  /* 9: non-alphanumeric character in the middle */
  /* "null\0inside" – note: strchr stops at first '\0', */
  /* so searching for 'i' should NOT find anything here */
  /* 9 */ check(ft_strchr(s5, 'i') == strchr(s5, 'i'));

  printf("===================================\n");
  printf("ft_strrchr\n");
  printf("===================================\n");
  char s6[] = "a\0b"; /* 'b' is after the NUL, so invisible to strrchr */

  /* 1: char at beginning (only occurrence) */
  /* "hello" -> last 'h' at index 0 */
  /* 1 */ check(ft_strrchr(s1, 'h') == strrchr(s1, 'h'));

  /* 2: char in the middle with multiple occurrences -> last one */
  /* "hello" -> 'l' at index 3 (not 2) */
  /* 2 */ check(ft_strrchr(s1, 'l') == strrchr(s1, 'l'));

  /* 3: char at the end */
  /* "end?" -> '?' last character */
  /* 3 */ check(ft_strrchr(s4, '?') == strrchr(s4, '?'));

  /* 4: multiple occurrences in longer string */
  /* "abcabc" -> last 'b' at index 4 */
  /* 4 */ check(ft_strrchr(s2, 'b') == strrchr(s2, 'b'));

  /* 5: char not present at all */
  /* "abcabc" -> 'x' not found → NULL */
  /* 5 */ check(ft_strrchr(s2, 'x') == strrchr(s2, 'x'));

  /* 6: all same char, last one at the end */
  /* "aaaa" -> 'a' should point to last char (index 3) */
  /* 6 */ check(ft_strrchr(s5, 'a') == strrchr(s5, 'a'));

  /* 7: search for '\0' terminator in non-empty string */
  /* should return pointer to terminating NUL */
  /* 7 */ check(ft_strrchr(s1, '\0') == strrchr(s1, '\0'));

  /* 8: empty string, search for '\0' */
  /* should return pointer to s3 (first byte, which is '\0') */
  /* 8 */ check(ft_strrchr(s3, '\0') == strrchr(s3, '\0'));

  /* 9: embedded NUL: search past it should fail */
  /* "a\0b" -> 'b' is after NUL, so strrchr should return NULL */
  /* 9 */ check(ft_strrchr(s6, 'b') == strrchr(s6, 'b'));

  printf("===================================\n");
  printf("ft_memchr\n");
  printf("===================================\n");
  char m1[] = "hello";
  char m2[] = "abcabc";
  unsigned char buf[] = {0, 1, 2, 3, 4, 5};
  char m3[] = {'A', (char)0x80, 'B', 0};

  /* 1: match at beginning */
  /* "hello" -> 'h' in first 5 bytes */
  /* 1 */ check(ft_memchr(m1, 'h', 5) == memchr(m1, 'h', 5));

  /* 2: match in the middle */
  /* "hello" -> first 'l' at index 2 */
  /* 2 */ check(ft_memchr(m1, 'l', 5) == memchr(m1, 'l', 5));

  /* 3: character not found */
  /* "hello" -> 'z' not present */
  /* 3 */ check(ft_memchr(m1, 'z', 5) == memchr(m1, 'z', 5));

  /* 4: search for '\0' (terminator) */
  /* "hello\0" -> '\0' at index 5, so n must be at least 6 */
  /* 4 */ check(ft_memchr(m1, '\0', 6) == memchr(m1, '\0', 6));

  /* 5: n == 0 → must always return NULL */
  /* even though 'h' is at s1[0], we search 0 bytes */
  /* 5 */ check(ft_memchr(m1, 'h', 0) == memchr(m1, 'h', 0));

  /* 6: binary buffer: find 0 */
  /* buf = {0,1,2,3,4,5} -> 0 at index 0 */
  /* 6 */ check(ft_memchr(buf, 0, 6) == memchr(buf, 0, 6));

  /* 7: binary buffer: find 3 in the middle */
  /* buf = {0,1,2,3,4,5} -> 3 at index 3 */
  /* 7 */ check(ft_memchr(buf, 3, 6) == memchr(buf, 3, 6));

  /* 8: multiple occurrences: must return first one */
  /* "abcabc" -> 'b' at index 1 (not 4) */
  /* 8 */ check(ft_memchr(m2, 'b', 6) == memchr(m2, 'b', 6));

  /* 9: high-bit byte: ensure unsigned-char behavior */
  /* s3 = {'A', 0x80, 'B', 0} -> search for 0x80 */
  /* 9 */ check(ft_memchr(m3, 0x80, 4) == memchr(m3, 0x80, 4));

  ft_memcmp_test();
  ft_strnstr_test();
  ft_atoi_test();
  return 0;
}

void ft_memcmp_test() {
  printf("===================================\n");
  printf("ft_memcmp\n");
  printf("===================================\n");
  int res;
  int expected;

  /* 1: equal buffers, full length */
  {
    char a1[] = "hello";
    char a2[] = "hello";

    res = ft_memcmp(a1, a2, 5);
    expected = memcmp(a1, a2, 5);
    /* 1 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 2: difference at first byte */
  {
    char a1[] = "hello";
    char a2[] = "jello";

    res = ft_memcmp(a1, a2, 5);
    expected = memcmp(a1, a2, 5);
    /* 2 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 3: difference in the middle */
  {
    char a1[] = "abcde";
    char a2[] = "abXde";

    res = ft_memcmp(a1, a2, 5);
    expected = memcmp(a1, a2, 5);
    /* 3 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 4: difference at the last compared byte */
  {
    char a1[] = "abcde";
    char a2[] = "abcdX";

    res = ft_memcmp(a1, a2, 5);
    expected = memcmp(a1, a2, 5);
    /* 4 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 5: difference exists, but after n bytes -> equal for given n */
  {
    char a1[] = "abcde";
    char a2[] = "abXde";

    res = ft_memcmp(a1, a2, 2); // only "ab" vs "ab"
    expected = memcmp(a1, a2, 2);
    /* 5 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 6: n == 0 → must return 0 (equal) */
  {
    char a1[] = "hello";
    char a2[] = "world";

    res = ft_memcmp(a1, a2, 0);
    expected = memcmp(a1, a2, 0);
    /* 6 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 7: embedded NULs, difference after '\0' must still be seen */
  {
    char a1[] = {'a', '\0', 'b', 'c'};
    char a2[] = {'a', '\0', 'd', 'c'};

    res = ft_memcmp(a1, a2, 4);
    expected = memcmp(a1, a2, 4);
    /* 7 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 8: high-bit bytes: unsigned-char behavior (first < second) */
  {
    unsigned char a1[] = {0x7F, 0x80};
    unsigned char a2[] = {0x7F, 0xFF};

    res = ft_memcmp(a1, a2, 2);
    expected = memcmp(a1, a2, 2);
    /* 8 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }

  /* 9: high-bit bytes: unsigned-char behavior (first > second) */
  {
    unsigned char a1[] = {0x7F, 0xFF};
    unsigned char a2[] = {0x7F, 0x80};

    res = ft_memcmp(a1, a2, 2);
    expected = memcmp(a1, a2, 2);
    /* 9 */ check((res == 0 && expected == 0) || (res < 0 && expected < 0) ||
                  (res > 0 && expected > 0));
  }
}

void ft_strnstr_test() {
  printf("===================================\n");
  printf("ft_strnstr\n");
  printf("===================================\n");

  char big1[] = "hello world";
  char big2[] = "foo bar baz";
  char big3[] = "aaaaa";
  char big4[] = "short";
  char empty[] = "";
  char big5[] = "abcde";

  /* 1: basic match fully inside len */
  /* 1 */ check(ft_strnstr(big1, "world", 11) == &big1[6]);

  /* 2: len too small to reach the whole match -> NULL */
  /* 2 */ check(ft_strnstr(big1, "world", 10) == NULL);

  /* 3: match at the beginning */
  /* 3 */ check(ft_strnstr(big2, "foo", 11) == &big2[0]);

  /* 4: needle not present at all -> NULL */
  /* 4 */ check(ft_strnstr(big2, "xyz", 11) == NULL);

  /* 5: overlapping / repeated chars */
  /* 5 */ check(ft_strnstr(big3, "aaa", 5) == &big3[0]);

  /* 6: overlapping, but len cuts it off so no full match */
  /* 6 */ check(ft_strnstr(big3, "aaa", 2) == NULL);

  /* 7: empty needle: must return haystack, even if len = 0 */
  /* 7 */ check(ft_strnstr(big4, "", 0) == big4);

  /* 8: empty haystack, non-empty needle -> NULL */
  /* 8 */ check(ft_strnstr(empty, "x", 1) == NULL);

  /* 9: match that ends exactly at len boundary */
  /* 9 */ check(ft_strnstr(big5, "de", 5) == &big5[3]);
}

void ft_atoi_test() {
  printf("===================================\n");
  printf("ft_atoi\n");
  printf("===================================\n");

  int res;
  int expected;

  /* 1: simple zero */
  res = ft_atoi("0");
  expected = atoi("0");
  /* 1 */ check(res == expected);

  /* 2: simple positive number */
  res = ft_atoi("42");
  expected = atoi("42");
  /* 2 */ check(res == expected);

  /* 3: simple negative number */
  res = ft_atoi("-42");
  expected = atoi("-42");
  /* 3 */ check(res == expected);

  /* 4: leading spaces */
  res = ft_atoi("   1234");
  expected = atoi("   1234");
  /* 4 */ check(res == expected);

  /* 5: mixed whitespace and negative sign */
  res = ft_atoi("\t\n  -567");
  expected = atoi("\t\n  -567");
  /* 5 */ check(res == expected);

  /* 6: explicit plus sign */
  res = ft_atoi("+90");
  expected = atoi("+90");
  /* 6 */ check(res == expected);

  /* 7: stops at first non-digit after digits */
  res = ft_atoi("4193 with words");
  expected = atoi("4193 with words");
  /* 7 */ check(res == expected);

  /* 8: no leading digits -> should return 0 */
  res = ft_atoi("words 987");
  expected = atoi("words 987");
  /* 8 */ check(res == expected);

  /* 9: large in-range value (INT_MAX on 32-bit) */
  res = ft_atoi("2147483647");
  expected = atoi("2147483647");
  /* 9 */ check(res == expected);
}
