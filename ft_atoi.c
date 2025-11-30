#include "libft.h"
#include <stddef.h>

int ft_atoi(const char *cptr) {
  int result;
  int sign;
  int i;

  result = 0;
  sign = 1;
  i = 0;

  while (ft_isspace(cptr[i])) {
    i++;
  }

  if (cptr[i] == '+' && cptr[i - 1] != '-') {
    i++;
  }

  if (cptr[i] == '-') {
    sign = -1;
    i++;
  }

  while (cptr[i] && cptr[i] >= 48 && cptr[i] <= 57) {
    result *= 10;
    result += cptr[i] - 48;
    i++;
  }

  result *= sign;
  return result;
}
