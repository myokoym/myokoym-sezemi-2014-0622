#include "user.h"
#include <stdio.h>

#define USAGE "Usage: recipe <ユーザー名 データファイル>... <ユーザーID> [レシピID]"

int
validate_arguments(int argc) {
  if (argc < 3) {
    return 1;
  }
  return 0;
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
    if (specified_user_id != -1 && specified_user_id != i + 1) {
      continue;
    }

    user_print_name(&user[i]);
    if (argc == (3 + (n_users * 2))) {
      if (sscanf(argv[2 + (n_users * 2)], "%d", &specified_recipe_id) == EOF) {
        fprintf(stderr, "%s\n", USAGE);
        return 1;
      }
      if (user_print_with_id(&user[i], specified_recipe_id) != 0) {
        fprintf(stderr, "%s\n", USAGE);
        return 1;
      }
    } else {
      user_print_all(&user[i]);
    }
    printf("\n");
  }

  return 0;
}
