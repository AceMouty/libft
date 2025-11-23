#include "libft.h"
void *ft_memmove(void *dest, const void *src, size_t n) {
  const unsigned char *src_ptr;
  unsigned char *dest_ptr;

  if (!src && !dest) {
    return NULL;
  } else if (dest == src || n == 0) {
    return dest;
  }

  src_ptr = src;
  dest_ptr = dest;

  // Stack memory "grows" in a descending direction
  // so if the dest address is less than the src, we know we are not
  // in the same memory reigon and can copy forward
  //
  // if dest is greater than src, then we are in the same memory reigon
  // and need to copy backwards in order to preserve values
  if (dest_ptr < src_ptr) {
    while (n--) {
      *dest_ptr++ = *src_ptr++;
    }
  } else {
    while (n--) {
      *--dest_ptr = *--src_ptr;
    }
  }

  return dest;
}
