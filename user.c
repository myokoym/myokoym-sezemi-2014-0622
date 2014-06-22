#include "user.h"
#include <stdio.h>

void
user_print_name(User *user) {
  printf("ユーザー名: %s\n", user->name);
}

int
user_scan_from_file(User *user, char *filename) {
  static int recipe_id = 1;
  int i;
  FILE *file;

  file = fopen(filename, "r");
  if (file == NULL) {
    return 1;
  }
  for (i = 0; fscanf(file,
                     "%s%s",
                     user->recipes[i].name,
                     user->recipes[i].url) != EOF; i++) {
    user->recipes[i].id = recipe_id;
    recipe_id++;
  }
  fclose(file);
  return 0;
}

void
user_print_all(User *user) {
  int i;

  for (i = 0; user->recipes[i].name[0] != '\0'; i++) {
    recipe_print(&user->recipes[i]);
  }
}

int
user_print_with_id(User *user, int id) {
  int i;

  for (i = 0; user->recipes[i].name[0] != '\0'; i++) {
    if (user->recipes[i].name[0] == '\0') {
      continue;
    }
    if (user->recipes[i].id == id) {
      recipe_print(&user->recipes[i]);
    }
  }

  return 0;
}
