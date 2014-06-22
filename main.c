#include "recipe.h"
#include <stdio.h>

#define USAGE "Usage: recipe recipe-data.txt"
#define LIST_SIZE 256

int
main(int argc, char *argv[]) {
  Recipe recipes[LIST_SIZE];

  if (validate_arguments(argc) != 0) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }
  if (scan(argv[1], recipes) != 0) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }
  print(recipes);

  return 0;
}
