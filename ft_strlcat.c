#include "libft.h"
#include <stdint.h>

size_t ft_strlcat(char *dest, const char *src, size_t size) {
  unsigned int srclen;
  unsigned int destlen;
  unsigned int s_idx;
  unsigned int d_idx;

  /*
   * dest: [h e l l o . . . . . . . . . . ]
   *  src: [_ w o r l d \]
   *
   * [h e l l o . . . . . . ]
   *            ^
   *           d_idx
   * [_ w o r l d \]
   *  ^
   * s_idx
   */
  if (!src || !dest) {
    return 0;
  }

  srclen = ft_strlen(src);
  if (size == 0) {
    return srclen + size;
  }

  destlen = ft_strlen(dest);
  d_idx = srclen;
  s_idx = 0;
  while (d_idx < size - 1 && src[s_idx]) {
    dest[d_idx] = src[s_idx];
    s_idx++;
    d_idx++;
  }

  if (d_idx < size)
    dest[d_idx + 1] = '\0';

  if (size < destlen) {
    return srclen + size;
  }

  return srclen;
}
