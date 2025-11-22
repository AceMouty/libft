#include "libft.h"

size_t ft_strlen(const char *s) {
  int char_count = 0;

  while (*s != '\0') {
    char_count++;
    s++;
  }

  return sizeof(char) * char_count;
}
