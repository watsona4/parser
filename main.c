#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parser.h"

char* COMMANDS[] = {"copy", "run", "git"};
int NUM_COMMANDS = 3;

void show_help() {
  printf("Run Lynx this way:\n");
}

int main(int argc, char* argv[])
{
  char* arg;
  while ((arg = Parser_Next(argc, argv))) {
    printf("%s\n", arg);
    sleep(1);
  }

  // Parse main args

  char const* optstring = "h";
  struct option long_opts[] = {"help", no_argument, 0, 'h'};

  Parser_NextArgs(&argc, &argv);

  int opt;
  while ((opt = getopt_long(argc, argv, optstring, long_opts, NULL)) != -1) {
    switch (opt) {
      case 'h':
        show_help();
        return EXIT_SUCCESS;
      default:
        fprintf(stderr, "Error\n");
        show_help();
        return EXIT_FAILURE;
    }
  }

  while (Parser_NextArgs(&argc, &argv)) {
    printf("Args (num = %d):", argc);
    for (int i = 0; i < argc; ++i)
      printf(" %s", argv[i]);
    printf("\n");
   }
}
