#include "libft.h"

static int int_len(long nbr);

char *ft_itoa(int n) {
  char *result;
  long value;
  int len;

  /*
   * Convert to long so INT_MIN can be safely negated.
   *
   * Example:
   * int min = -2147483648
   *
   * If we did this as an int:
   * min = -min;
   *
   * that would overflow.
   */
  value = n;

  /*
   * Count how many characters are needed.
   *
   * Examples:
   * 0      -> 1
   * 42     -> 2
   * -42    -> 3
   * 12345  -> 5
   */
  len = int_len(value);

  /*
   * Allocate space for the digits plus the null terminator.
   */
  result = malloc(sizeof(char) * (len + 1));
  if (result == NULL)
    return (NULL);

  /*
   * Null-terminate the string first.
   * We will fill the number from right to left.
   */
  result[len] = '\0';

  /*
   * Handle negative numbers.
   *
   * Store the sign at the beginning, then make nbr positive
   * so digit extraction works normally.
   */
  if (value < 0) {
    result[0] = '-';
    value = -value;
  }

  /*
   * Special case for 0.
   *
   * The digit-building loop below only runs while nbr > 0,
   * so without this, "0" would never get written.
   */
  if (value == 0)
    result[0] = '0';

  /*
   * Fill the string from the end toward the front.
   *
   * nbr % 10 gives the last digit.
   * Adding '0' converts that digit to its character form.
   *
   * Example:
   * 123 % 10 = 3 -> '3'
   */
  while (value > 0) {
    result[len - 1] = (value % 10) + '0';
    value = value / 10;
    len--;
  }

  return (result);
}

static int int_len(long value) {
  int len;

  len = 0;

  /*
   * Negative numbers need one extra character for '-'.
   * Then make the number positive so we can count digits.
   */
  if (value < 0) {
    len++;
    value = -value;
  }

  /*
   * Zero still needs one character: "0".
   */
  if (value == 0)
    return (1);

  /*
   * Count digits by repeatedly removing the last digit.
   *
   * Example:
   * 123 -> 12 -> 1 -> 0
   *
   * That is 3 digits.
   */
  while (value > 0) {
    len++;
    value = value / 10;
  }

  return (len);
}
