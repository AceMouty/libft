#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len) {
  size_t hay_pos;    // current position in haystack
  size_t needle_pos; // current position in needle

  hay_pos = 0;
  needle_pos = 0;

  if (needle[0] == '\0') {
    return (char *)haystack;
  }

  while (haystack[hay_pos] && hay_pos < len) {
    while (haystack[hay_pos + needle_pos] == needle[needle_pos] &&
           haystack[hay_pos + needle_pos] && hay_pos + needle_pos < len) {
      needle_pos++;
      if (needle[needle_pos] == 0) {
        return (char *)haystack + hay_pos;
      }
    }

    hay_pos++;
    needle_pos = 0;
  }

  return NULL;
}
