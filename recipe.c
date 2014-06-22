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
  for (i = 0; fscanf(file, "%s", recipes[i].name) != EOF; i++) {
  }
  fclose(file);
  return 0;
}

void
print_all(Recipe *recipes) {
  int i;
  for (i = 0; recipes[i].name[0] != '\0'; i++) {
    printf("%d: %s\n", i + 1, recipes[i].name);
  }
}

int
print_with_id(Recipe *recipes, int id) {
  int index = id - 1;
  if (recipes[index].name[0] == '\0') {
    return 1;
  }
  printf("%d: %s\n", id, recipes[index].name);
  return 0;
}
