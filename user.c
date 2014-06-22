#include "user.h"
#include <stdio.h>
#include <stdlib.h>

void
user_print_name(User *user) {
  printf("ユーザー名: %d: %s\n", user->id, user->name);
}

int
user_scan_recipes_from_file(User *user, char *filename) {
  int i;
  FILE *file;
  char line[1024];

  file = fopen(filename, "r");
  if (file == NULL) {
    return 1;
  }

  for (i = 0; fgets(line, 1024, file) != NULL; i++) {
    user->recipes[i] = recipe_new();
    sscanf(line, "%s%s", user->recipes[i]->name, user->recipes[i]->url);
  }
  user->n_recipes = i;

  fclose(file);
  return 0;
}

void
user_print_all(User *user) {
  int i;

  for (i = 0; i < user->n_recipes; i++) {
    recipe_print(user->recipes[i]);
  }
}

int
user_print_with_id(User *user, int id) {
  int i;

  for (i = 0; i < user->n_recipes; i++) {
    if (user->recipes[i]->id == id) {
      recipe_print(user->recipes[i]);
    }
  }

  return 0;
}
