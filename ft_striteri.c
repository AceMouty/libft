#include "libft.h"


void ft_striteri(char *s, void (*callback_ptr)(unsigned int, char*))
{
  unsigned int i;

  if(s == NULL || callback_ptr == NULL)
    return;

  i = 0;
  while(s[i])
  {
    callback_ptr(i, &s[i]);
    i++;
  }

  return;
}
