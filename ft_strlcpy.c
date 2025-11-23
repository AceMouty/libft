#include "libft.h"
#include <stdint.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size) {
  unsigned int srclen;
  unsigned int idx;

  if (!src || !dest) {
    return 0;
  }

  srclen = ft_strlen(src);
  if (size == 0) {
    return srclen;
  }

  idx = 0;
  while (idx + 1 < size && src[idx] != '\0') {
    dest[idx] = src[idx];
    idx++;
  }

  dest[idx] = '\0';

  return srclen;
}
