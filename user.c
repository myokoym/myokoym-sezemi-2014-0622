#include "user.h"
#include <stdio.h>

void
user_print_name(User *user) {
  printf("ユーザー名: %s\n", user->name);
}

int
user_scan_from_file(User *user, char *filename) {
  int i;
  FILE *file;
  Recipe *recipes = user->recipes;

  file = fopen(filename, "r");
  if (file == NULL) {
    return 1;
  }
  for (i = 0; fscanf(file,
                     "%s%s",
                     recipes[i].name,
                     recipes[i].url) != EOF; i++) {
  }
  fclose(file);
  return 0;
}

void
user_print_all(User *user) {
  int i;
  Recipe *recipes = user->recipes;

  for (i = 0; recipes[i].name[0] != '\0'; i++) {
    recipe_print(&recipes[i], i + 1);
  }
}

int
user_print_with_id(User *user, int id) {
  int i = id - 1;
  Recipe *recipes = user->recipes;

  if (recipes[i].name[0] == '\0') {
    return 1;
  }
  recipe_print(&recipes[i], id);
  return 0;
}
