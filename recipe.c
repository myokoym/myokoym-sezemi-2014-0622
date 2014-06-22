#include "recipe.h"
#include <stdio.h>

int
validate_arguments(int argc) {
  if (argc != 2) {
    return 1;
  }
  return 0;
}

int
scan(char *filename, Recipe *recipes) {
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
print(Recipe *recipes) {
  int i;
  for (i = 0; recipes[i].name[0] != '\0'; i++) {
    printf("%s\n", recipes[i].name);
  }
}
