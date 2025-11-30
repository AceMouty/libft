#include "check.h"
#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

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

  return 0;
}
