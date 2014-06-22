#include "recipe.h"
#include <stdio.h>

#define USAGE "Usage: recipe recipe-data.txt [ID]"
#define LIST_SIZE 256

int
main(int argc, char *argv[]) {
  Recipe recipes[LIST_SIZE];

  if (validate_arguments(argc) != 0) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }

  if (scan_from_file(argv[1], recipes) != 0) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }

  if (argc == 3) {
    if (print_with_id(recipes, atoi(argv[2]))) {
      fprintf(stderr, "%s\n", USAGE);
      return 1;
    }
  } else {
    print_all(recipes);
  }

  return 0;
}
