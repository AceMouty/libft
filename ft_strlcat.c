#include "libft.h"
#include <stdint.h>

size_t ft_strlcat(char *dest, const char *src, size_t size) {
  /*
   * dest: [h e l l o . . . . . . . . . . ]
   *  src: [_ w o r l d \]
   *
   * [h e l l o . . . . . . ]
   *            ^
   *           dlen
   * [_ w o r l d \]
   *  ^
   * slen
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
  size_t dlen;
  size_t i;

  // find dlen but dont go past size
  dlen = ft_strlen(dest);

  // if we "consumed" size bytes without seeing \0
  // dest isnt a proper C string
  if (dlen == size) {
    return size + ft_strlen(src);
  }

  // start appending at the end of dest
  i = 0;
  // copy while we have room for at least one more char + '\0'
  while (src[i] && (dlen + i + 1) < size) {
    dest[dlen + i] = src[i];
    i++;
  }

  if (dlen + i < size) // always true if we got here with a proper C string
    dest[dlen + i] = '\0';

  return dlen + ft_strlen(src);
  // size_t dlen;
  // size_t slen;
  // size_t space;
  // size_t to_copy;
  //
  // slen = ft_strlen(src);
  // dlen = ft_strlen(dest);
  //
  // if (size <= dlen) {
  //   return size + slen;
  // }
  //
  // space = size - dlen - 1;
  //
  // if (slen < space)
  //   to_copy = slen;
  // else
  //   to_copy = space;
  //
  // if (to_copy > 0) {
  //   ft_memcpy(dest + dlen, src, to_copy);
  // }
  //
  // dest[dlen + to_copy] = '\0';
  // /* Length we *tried* to build */
  // return (dlen + slen);
}
