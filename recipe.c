#include "recipe.h"
#include <stdio.h>

int
validate_arguments(int argc) {
  if (argc < 2) {
    return 1;
  }
  return 0;
}

int
scan_from_file(char *filename, Recipe *recipes) {
  int i;
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL) {
    return 1;
  }
  for (i = 0;
       fscanf(file, "%s%s", recipes[i].name, recipes[i].url) != EOF;
       i++) {
  }
  fclose(file);
  return 0;
}

void
print_all(Recipe *recipes) {
  int i;
  for (i = 0; recipes[i].name[0] != '\0'; i++) {
    printf("%d: %s %s\n", i + 1, recipes[i].name, recipes[i].url);
  }
}

int
print_with_id(Recipe *recipes, int id) {
  int i = id - 1;
  if (recipes[i].name[0] == '\0') {
    return 1;
  }
  printf("%d: %s %s\n", id, recipes[i].name, recipes[i].url);
  return 0;
}
