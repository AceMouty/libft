int ft_isalpha(int c) {
  // ref: https://www.ascii-code.com/
  // numbers here are decimal ascii-code range
  if (c >= 65 && c <= 90) {
    return 1;
  } else if (c >= 97 && c <= 122) {
    return 1;
  }

  return 0;
}
