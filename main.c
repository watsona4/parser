#include <stdio.h>

#include "parser.h"

char* COMMANDS[] = {"copy", "run", "git"};
int NUM_COMMANDS = 3;

int main(int argc, char* argv[])
{
  char* arg;
  while ((arg = Parser_Next(argc, argv)))
    printf("%s\n", arg);

  /* while (Parser_NextArgs(&argc, &argv)) { */
  /*   printf("Args (num = %d):", argc); */
  /*   for (int i = 0; i < argc; ++i) */
  /*     printf(" %s", argv[i]); */
  /* } */
}
