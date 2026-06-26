#include "libft.h"

size_t ft_strlen(const char *s) {
  size_t slen = 0;

  while (s[slen] != '\0') {
    slen++;
  }

  return slen;
}
