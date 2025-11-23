#ifndef _CHECK_H
#define _CHECK_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define FG_GREEN "\033[32m"
#define FG_RED "\033[31m"
#define FG_RESET "\033[0m"

void check(bool success);
#endif
