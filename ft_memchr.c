#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n) {
  unsigned char target;
  unsigned char *src;
  size_t idx;

  target = c;
  src = (unsigned char *)s;
  idx = 0;

  while (idx < n) {
    if (src[idx] == target) {
      return (void *)&src[idx];
    }
    idx++;
  }

  return NULL;
}
