#include "parser.h"

#include <string.h>

#define CR_BEGIN static int state=0; switch(state) { case 0:
#define CR_RETURN(x) do { state=__LINE__; return x;	\
    case __LINE__:; } while (0)
#define CR_FINISH }

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
  static int i, state = 0;

  switch(state) {

  case 0:;  // first run
    for (i = 1; i < argc; ++i) {
      if (state == 0 && argv[i][0] != '-') {
        state = 1;
        return argv[i];
      } else if (SubcommandList_Contains(argv[i])) {
        return argv[i];
      }
  case 1:;  // return from yield
    }
    state = -1;
  default:
    return NULL;
  }
}

int Parser_NextArgs(int* argc, char** argv[])
{
/*   static int i, init = 0; */
/*   CR_BEGIN; */
/*   for (i = 1; i < argc; ++i) { */
/*     if (argv[i][0] != '-' && init == 0) { */
/*       init = 1; */
/*       CR_RETURN(argv[i]); */
/*     } else { */
/*       if (SubcommandList_Contains(argv[i])) */
/* 	CR_RETURN(argv[i]); */
/*     } */
/*   } */
/*   CR_RETURN(NULL); */
/*   CR_FINISH; */
}
