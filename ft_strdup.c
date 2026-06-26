#include "libft.h"

char *ft_strdup(const char *s) {
  char *cpy;
  size_t i;

  /* 
  * allocate s + 1 memory space 
  * the +1 is for NULL-terminating character
  * since ft_strlen does not include NULL-termination in the result
  */
  cpy = (char *) malloc(ft_strlen(s) + 1);
  if(!cpy)
    return NULL;

  // loop and copy over data from s to 
  i = 0;
  while(s[i])
  {
    cpy[i] = s[i];
    i++;
  }

  cpy[i] = '\0';

  return cpy;
}
