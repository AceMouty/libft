int ft_isalnum(int c) {
  unsigned char uc;
  uc = (unsigned char)c;

  return ((uc >= 'a' && uc <= 'z') || (uc >= 'A' && uc <= 'Z') ||
          (uc >= '0' && uc <= '9'));
}
