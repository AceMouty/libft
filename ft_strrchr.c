#include "libft.h"

char *ft_strrchr(const char *s, int c) {
  size_t slen;
  char target;

  slen = ft_strlen(s) + 1; // include \0 as a taret to check
  target = (char)c;

  while (slen--) {
    if (s[slen] == target) {
      return (char *)&s[slen];
    }
  }

  if (s[slen] == target) { // slen is 0
    return (char *)&s[slen];
  }

  return NULL;
}
