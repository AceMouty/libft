#include "libft.h"

char *ft_strmapi(const char *s, char (*callback_ptr)(unsigned int, char))
{
  unsigned int i;
  char *res;
  size_t s_len;

  if(s == NULL || callback_ptr == NULL)
    return NULL;


  s_len = ft_strlen(s);
  res = malloc((s_len + 1) * sizeof(char));
  if (res == NULL)
    return NULL;

  i = 0;
  while(i < s_len)
  {
    res[i] = callback_ptr(i, s[i]);
    i++;
  }

  res[i] = '\0';

  return res;
}
