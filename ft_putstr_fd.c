#include <unistd.h>
#include "libft.h"

void ft_putstr_fd(char *str, int fd)
{
  if(!str)
    return;

  write(fd, str, ft_strlen(str));
}
