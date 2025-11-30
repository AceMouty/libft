#include "libft.h"

size_t ft_strnlen(const char *s, size_t maxlen) {
  size_t slen;
  slen = 0;
  while (slen < maxlen && s[slen] != '\0') {
    slen++;
  }

  return slen;
}
