#include "libft.h"

char *ft_strdup(const char *s, size_t n) {
  size_t slen;
  char *cpy;

  slen = ft_strlen(s);
  // +1 to include a spot for NUL termination
  cpy = (char *)ft_calloc(slen + 1, n);
  cpy = (char *)ft_memcpy(cpy, s, slen + 1);

  return cpy;
}
