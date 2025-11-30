#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n) {
  // memory areas to compare
  unsigned char *a1;
  unsigned char *a2;
  size_t idx;

  a1 = (unsigned char *)s1;
  a2 = (unsigned char *)s2;
  idx = 0;

  while (idx < n) {
    if ((unsigned char)a1[idx] != (unsigned char)a2[idx]) {
      return (unsigned char)a1[idx] - (unsigned char)a2[idx];
    }

    idx++;
  }

  return 0;
}
