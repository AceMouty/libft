#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>
#include <stdlib.h>

char *ft_strchr(const char *s, int c);
char *ft_strnstr(const char *str1, const char *str2, size_t len);
char *ft_strrchr(const char *s, int c);
int ft_atoi(const char *cptr);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_memcmp(const void *s1, const void *s2, size_t n);
int ft_tolower(int c);
int ft_toupper(int c);
size_t ft_strlcat(char *dest, const char *src, size_t size);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlen(const char *s);
size_t ft_strnlen(const char *s, size_t maxlen);
void *ft_memchr(const void *s, int c, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
int ft_isspace(int c);
void *ft_calloc(size_t nelem, size_t size);
char *ft_strdup(const char *s, size_t n);
#endif
