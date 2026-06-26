#include "libft.h"
void *ft_memmove(void *dest, const void *src, size_t n) {
  const unsigned char *src_ptr;
  unsigned char *dest_ptr;

  if (!src && !dest) 
    return NULL;
 
  if (dest == src || n == 0) 
    return dest;
  

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
    /*
     * dest_ptr and src_ptr currently point to the START of their regions.
     *
     * Because we are copying backward, we need to start from the END.
     * Adding n moves both pointers one byte past the last byte to copy.
     */
    dest_ptr += n;
    src_ptr += n;
    while (n--) {
      *--dest_ptr = *--src_ptr;
    }
  }

  return dest;
}
