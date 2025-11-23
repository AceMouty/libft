#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n) {
  const unsigned char *src_ptr = src;
  unsigned char *dest_ptr = dest;

  if (src == NULL || dest == NULL) {
    return dest;
  }

  while (n--) {
    *dest_ptr++ = *src_ptr++;
  }

  return dest;
}
