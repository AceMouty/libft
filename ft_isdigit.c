int ft_isdigit(int c) {
  // ref: https://www.ascii-code.com/
  // numbers here are decimal ascii-code range
  if (c >= 48 && c <= 57) {
    return 1;
  }

  return 0;
}
