#include "libft.h"

void *ft_calloc(size_t nelem, size_t size) {
  unsigned char *tmp;
  size_t i;

  i = 0;
  tmp = malloc(nelem * size);

  if (!tmp)
    return NULL;

  while (i < nelem * size) {
    tmp[i++] = 0;
  }

  return tmp;
}
