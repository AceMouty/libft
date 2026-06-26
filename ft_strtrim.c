#include "libft.h"

static int to_trim(const char *set, char c);
static char *new_str(const char *s, size_t start, size_t len);

char *ft_strtrim(const char *s, const char *set)
{
  int i;
  int j;

  i = 0;
  j = ft_strlen(s) - 1;

  if(ft_strlen(s) == 0)
    return ft_strdup("");

  // scan from the front until we dont get a match from the set
  while(to_trim(set, s[i]))
   i++;

  // scan from the end until we dont get a match from the set
  while(to_trim(set, s[j]))
   j--;

  // now that we have our two indecies craft a new string
  return new_str(s, i, j - (i - 1));
}

static int to_trim(const char *set, char c)
{
  int i;

  i = 0;

  while(set[i]) 
  {
    if(c == set[i])
      return 1;
    i++;
  }

  return 0;
}

static char *new_str(const char *s, size_t start, size_t len)
{
  char *str;
  size_t i; // offset to use when copying data

  if(len <= 0 || start > ft_strlen(s))
    return ft_strdup("");

  str = ft_calloc(len + 1, sizeof(char));
  if(!str)
    return NULL;

  i = 0;
  while(i < len)
  {
    str[i] = s[start + i];
    i++;
  }

  return str;
}
