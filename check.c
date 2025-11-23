#include "check.h"

void check(bool success) {
  char buffer[128];
  int len;

  if (success) {
    len = snprintf(buffer, sizeof(buffer), "%s.OK%s\n", FG_GREEN, FG_RESET);
  } else {
    len = snprintf(buffer, sizeof(buffer), "%s.KO%s\n", FG_RED, FG_RESET);
  }

  if (len > 0)
    write(1, buffer, (size_t)len);
}
