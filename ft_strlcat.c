#include "libft.h"
#include <stdint.h>

size_t ft_strlcat(char *dest, const char *src, size_t dsize) {
  size_t dlen;
  size_t i;

  dlen = ft_strnlen(dest, dsize);

  if (dlen == dsize) {
    return dsize + ft_strlen(src);
  }

  // start appending at the end of dest
  i = 0;
  // copy while we have room for at least one more char
  // leaving space for NUL
  while (src[i] && (dlen + i + 1) < dsize) {
    dest[dlen + i] = src[i];
    i++;
  }

  if (dlen + i < dsize) // always true if we got here with a proper C string
    dest[dlen + i] = '\0';

  return dlen + ft_strlen(src);
}
