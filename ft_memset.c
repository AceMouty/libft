#include "libft.h"

void *ft_memset(void *s, int c, size_t n) {
  unsigned char *ptr = s;
  while (n--) {
    // WTF...yea I know, heres whats happening
    // 1. use current value of ptr (before increment)
    // 2. dereference the pointer
    // 3. assign value
    // 4. increment
    *ptr++ = c;
  }

  return s;
}
