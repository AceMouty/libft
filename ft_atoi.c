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

  if (cptr[i] == '+' || cptr[i] == '-')
  {
    if (cptr[i] == '-')
      sign = -1;
    i++;
  }

  // using the chars here is a ASCII trick
  // the comparison and math operates on the backing number value
  // of the char(s)
  while (cptr[i] && cptr[i] >= '0' && cptr[i] <= '9') {
    result *= 10;
    result += cptr[i] - '0';
    i++;
  }

  result *= sign;
  return result;
}
