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

  /* Loop over command-line, yielding the subcommands. On entry, state is 0.
   * In this case, advance until argument doesn't start with "-" and flip to
   * state 1. (Assumes no args to executable that don't start with hyphen.)
   * Then return the argument (first subcommand). Upon reentry, state is 1.
   * In state 1, loop until the argument is in the list of subcommands. Once
   * all arguments are evaluated, state is -1 and NULL is returned. This is
   * equivalent to the following Python code:
   *
   * state = 0
   * for arg in argv[1:]:
   *   if state == 0 and !arg.startswith('-'):
   *     state = 1
   *     yield arg
   *   elif arg in SUBCOMMANDS:
   *     yield arg
   */

  switch(state) {
  case 0:  // first run
    ptr = &argv[1];  // skip command name
    while(*ptr) {
      if (state == 0 && *ptr[0] != '-') {
        state = 1;  // Flip states
      } else if (SubcommandList_Contains(*ptr)) {
        ;  // Noop, just escape the else
      } else {
  case 1:  // return from yield
        ++ptr;
        continue;
      }
      return *ptr;
    }
    state = -1;
  default:  // if in final state
    return NULL;
  }
}

int Parser_NextArgs(int* argc, char** argv[])
{
  static int state = 0;
  static char** ptr = NULL;

  /* Loop over command-line, yielding the subcommand arguments. On entry,
   * state is 0. In this case, advance until argument doesn't start with "-"
   * and flip to state 1. (Assumes no args to executable that don't start
   * with hyphen.) Then set return the number of arguments to the first
   * subcommand. Upon reentry, state is 1. In state 1, set argv to ptr and
   * advance ptr until the argument is in the list of subcommands; then
   * return the number of arguments to that subcommand. Once all arguments
   * are evaluated, state is -1 and NULL is returned. If "++" is encountered,
   * skip the next argument.
   */

  switch(state) {
  case 0:  // first run
    ptr = *argv;
    while(*ptr) {
      if (state == 0 && *ptr[0] != '-' && ptr != *argv) {
        state = 1;  // Flip states
      } else if (SubcommandList_Contains(*ptr)) {
        ;  // Noop, just escape the else
      } else if (strcmp(*ptr, "++") == 0) {
        ++ptr;  // Skip next argument
      } else {
        ++ptr;
        continue;
  case 1:  // return from yield
        *argv = ptr;
        ++ptr;
        continue;
      }
      *argc = ptr - *argv;
      return 1;
    }
    state = -1;
    *argc = ptr - *argv;
    return 1;
  default:  // if in final state
    return 0;
  }
}
