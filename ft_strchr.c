#include "libft.h"

char *ft_strchr(const char *s, int c) {
  int idx;
  char target;

  idx = 0;
  target = (char)c;

  // scan for target char
  while (s[idx]) {
    if (s[idx] == target) {
      return (char *)&s[idx];
    }
    idx++;
  }

  // check for \0
  if (s[idx] == target) {
    return (char *)&s[idx];
  }

  return NULL;
}
