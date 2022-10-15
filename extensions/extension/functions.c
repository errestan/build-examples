// Include C headers.
#include <errno.h>
#include <stdio.h>
#include <string.h>

// Include GNU Make headers.
#include <gnumake.h>

// Include Custom headers.
#include "functions.h"

char *to_lower(const char *name, unsigned int argc, char **argv) {
  int len = strlen(argv[0]);
  int pos = 0;

  char *buf = gmk_alloc(len + 1);

  if (NULL == buf) {
    fprintf(stderr, "Allocation failed, %s\n", strerror(errno));
    return NULL;
  }

  while (argv[0][pos]) {
    if (argv[0][pos] >= 'A' && argv[0][pos] <= 'Z') {
      buf[pos] = argv[0][pos] + ('a' - 'A');
    } else {
      buf[pos] = argv[0][pos];
    }

    pos++;
  }

  return buf;
}

char *to_upper(const char *name, unsigned int argc, char **argv) {
  int len = strlen(argv[0]);
  int pos = 0;

  char *buf = gmk_alloc(len + 1);

  if (NULL == buf) {
    fprintf(stderr, "Allocation failed, %s\n", strerror(errno));
    return NULL;
  }

  while (argv[0][pos]) {
    if (argv[0][pos] >= 'a' && argv[0][pos] <= 'z') {
      buf[pos] = argv[0][pos] + ('A' - 'a');
    } else {
      buf[pos] = argv[0][pos];
    }

    pos++;
  }

  return buf;
}
