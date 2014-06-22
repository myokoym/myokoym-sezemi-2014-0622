#include "../lib/user.h"
#include <stdio.h>
#include <stdlib.h>

#define USAGE "Usage: recipe <ユーザー名 データファイル>... <ユーザーID> [レシピID]"

int
validate_arguments(int argc) {
  if (argc < 3) {
    return 1;
  }
  return 0;
}

int
recipe_print(Recipe *recipe) {
  printf("%d: %s %s\n", recipe->id, recipe->name, recipe->url);
  return 0;
}

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

void
user_print_with_id(User *user, int id) {
  Recipe *recipe;
  recipe = user_get_recipe_by_id(user, id);
  if (recipe == NULL) {
    return;
  }
  recipe_print(recipe);
}

int
main(int argc, char *argv[]) {
  int n_users = (argc - 2) / 2;
  User user[n_users];
  int i;
  int specified_user_id;
  int specified_recipe_id;

  if (validate_arguments(argc) != 0) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }

  for (i = 0; i < n_users; i++) {
    user[i].id = i + 1;
    user[i].name = argv[1 + (i * 2)];
    if (user_scan_recipes_from_file(&user[i], argv[2 + (i * 2)]) != 0) {
      fprintf(stderr, "%s\n", USAGE);
      return 1;
    }
  }

  if (sscanf(argv[1 + (n_users * 2)], "%d", &specified_user_id) == EOF) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }

  for (i = 0; i < n_users; i++) {
    if (specified_user_id != -1 && specified_user_id != user[i].id) {
      continue;
    }

    user_print_name(&user[i]);
    if (argc == (3 + (n_users * 2))) {
      if (sscanf(argv[2 + (n_users * 2)], "%d", &specified_recipe_id) == EOF) {
        fprintf(stderr, "%s\n", USAGE);
        return 1;
      }
      user_print_with_id(&user[i], specified_recipe_id);
    } else {
      user_print_all(&user[i]);
    }
    printf("\n");
  }

  return 0;
}
