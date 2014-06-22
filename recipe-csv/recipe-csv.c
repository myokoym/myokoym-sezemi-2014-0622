#include "../lib/user.h"
#include <stdio.h>
#include <stdlib.h>

#define USAGE "Usage: recipe-csv <ユーザー名 データファイル>..."

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
print_csv(User *user) {
  int i, j;

  for (i = 0; i < user->n_recipes; i++) {
    printf("%d,%s,%d,%s,%s\n", user->id, user->name,
           user->recipes[i]->id, user->recipes[i]->name, user->recipes[i]->url);
  }
}

int
main(int argc, char *argv[]) {
  int n_users = (argc - 1) / 2;
  User user[n_users];
  int i;

  for (i = 0; i < n_users; i++) {
    user[i].id = i + 1;
    user[i].name = argv[1 + (i * 2)];
    if (user_scan_recipes_from_file(&user[i], argv[2 + (i * 2)]) != 0) {
      fprintf(stderr, "%s\n", USAGE);
      return 1;
    }
  }

  for (i = 0; i < n_users; i++) {
    print_csv(&user[i]);
  }

  return 0;
}
