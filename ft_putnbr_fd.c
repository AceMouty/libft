#include "libft.h"

static void putlong_fd(long n, int fd);
static  char to_char(const long n);

// the trick is that integers are not already printable characters
// so we have to unpack a number down to the ones place
// and convert to its ASCII character symbol and then work our way back up
void ft_putnbr_fd(int n, int fd)
{
  long num;

  // cast to a long to widen the container to avoid complexities
  num = n;
  if(n < 0)
  {
    ft_putchar_fd('-', fd);
    num = -num;
  }

  putlong_fd(num, fd);
}

static void putlong_fd(long n, int fd)
{

   /*
    * use recursion to solve the "put digits in the correct order" problem
    *
    * example:
    * putnbr(1234)
    *   putnbr(123)
    *     putnbr(12)
    *        putnbr(1)
    *            print '1' <- write this first
    *        print '2' <- then this
    *    print '3' <- then this
    * print '4' <- then this
    */
  if(n >= 10) 
  {
    putlong_fd(n / 10, fd);
  }

  // take the last numeric digit, then shift it into the character range for digits.
  ft_putchar_fd(to_char(n), fd);
}

static char to_char(const long n)
{
  /*
   * This is a digit-to-character conversion trick.
   *
   * n % 10 gives us the numeric value of the last digit.
   * Example: 42 % 10 == 2
   *
   * Character digits are stored in order:
   * 
   * ASCII: 48   49   ...      57
   *  CHAR: '0', '1', '2', ... '9'
   *
   * So adding the numeric digit as an offset from '0'
   * gives us the matching character digit.
   *
   * Example:
   * 2 + '0' == '2'
   */
  return ((n % 10) + '0');
}
