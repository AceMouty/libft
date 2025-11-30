#include "libft.h"
#include <stdint.h>

size_t ft_strlcat(char *dest, const char *src, size_t size) {
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
   *
   * - Append src to the end of dest, but write at most destsize - 1 chars total
   *   into dst (including the original content of dst).
   *
   * - Always NUL-terminate (if dstsize is not 0 and dst is NUL-terminated).
   *
   * - Return the length of the string it tried to create, i.e.
   *    - If dstsize > strlen(dst): strlen(dst) + strlen(src)
   *    - If dstsize <= strlen(dst): dstsize + strlen(src)
   *      (this indicates truncation happened)
   */
  unsigned int slen;
  unsigned int dlen;
  int i;

  slen = ft_strlen(src);
  dlen = 0;

  // find dlen but dont go past size
  while (dlen < size && dest[dlen] != '\0') {
    dlen++;
  }

  // if we "consumed" size bytes without seeing \0
  // dest isnt a proper C string
  if (dlen == size) {
    return size + slen;
  }

  // start appending at the end of dest
  i = 0;
  // copy while we have room for at least one more char + '\0'
  while (src[i] && (dlen + i) < (size - 1)) {
    dest[dlen + i] = src[i];
    i++;
  }

  if (dlen + i < size)
    dest[dlen + i] = '\0';

  return dlen + slen;
}
