#include "libft.h"

void ft_bzero(void *s, size_t n) {
  unsigned char *ptr = s;
  // any non-zero value in c evals to true
  // so this is the same as n-- != 0
  while (n--) {
    *ptr++ = 0;
  }
}
