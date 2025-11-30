#include "libft.h"

int ft_isspace(int c) {
  /*
   * Possible whitespace characters
   *
   * \t -> tab
   * \n -> new line
   * \v -> vertical tab
   * \f -> form feed
   * \r -> carriage return
   * _ -> space
   *
   */

  if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32) {
    return 1;
  }

  return 0;
}
