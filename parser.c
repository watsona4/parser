#include "parser.h"

#include <stdio.h>
#include <string.h>

extern char* COMMANDS[];
extern int NUM_COMMANDS;

int SubcommandList_Contains(char const* name)
{
  for (int j = 0; j < NUM_COMMANDS; ++j)
    if (strcmp(name, COMMANDS[j]) == 0)
      return 1;
  return 0;
}

char* Parser_Next(int argc, char* argv[])
{
  static int state = 0;
  static char** ptr = NULL;

  switch(state) {
  case 0:  // first run
    ptr = &argv[1];
    while(*ptr) {
      if (state == 0 && *ptr[0] != '-') {
        state = 1;
        return *ptr;
      } else if (SubcommandList_Contains(*ptr)) {
        return *ptr;
      }
  case 1:  // return from yield
    ++ptr;
    }
    state = -1;
  default:
    return NULL;
  }
}

int Parser_NextArgs(int* argc, char** argv[])
{
  static int state = 0;
  static char** ptr = NULL;

  switch(state) {
  case 0:  // first run
    ptr = *argv;
    while(*ptr) {
      if (state == 0 && *ptr[0] != '-' && ptr != *argv) {
        state = 1;
        *argc = ptr - *argv;
        return 1;
      } else if (SubcommandList_Contains(*ptr)) {
        *argc = ptr - *argv;
        return 1;
      } else if (strcmp(*ptr, "++") == 0) {
        ++ptr;
        *argc = ptr - *argv;
        return 1;
  case 1:  // return from yield
        *argv = ptr;
      }
    ++ptr;
    }
    state = -1;
    *argc = ptr - *argv;
    return 1;
  default:
    return 0;
  }
}
