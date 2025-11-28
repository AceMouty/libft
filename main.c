#include "check.h"
#include "libft.h"
#include <assert.h>
#include <bsd/string.h>
#include <unistd.h>

int main(void) {
  char src[] = "coucou";
  char dest[10];

  // ===================================
  // ft_strlcpy
  // ===================================
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

  // ===================================
  // ft_strlcat
  // ===================================
  char str[] = " world";
  char buff[12];
  strlcpy(buff, "Hello", 6);
  printf("Buff: %s\n", buff);

  strlcat(buff, str, 12);
  printf("Buff: %d\n", buff[ft_strlen(buff) + 1]);

  write(1, "\n", 1);
  return 0;
}
