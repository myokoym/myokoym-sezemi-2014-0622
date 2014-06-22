#include "user.h"
#include <stdio.h>

#define USAGE "Usage: recipe ユーザーID データファイル [レシピID]"
#define LIST_SIZE 256

int
validate_arguments(int argc) {
  if (argc < 3) {
    return 1;
  }
  return 0;
}

int
main(int argc, char *argv[]) {
  User user;

  if (validate_arguments(argc) != 0) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }

  user.name = argv[1];
  user_print_name(&user);

  if (user_scan_from_file(&user, argv[2]) != 0) {
    fprintf(stderr, "%s\n", USAGE);
    return 1;
  }

  if (argc == 4) {
    if (user_print_with_id(&user, atoi(argv[3])) != 0) {
      fprintf(stderr, "%s\n", USAGE);
      return 1;
    }
  } else {
    user_print_all(&user);
  }

  return 0;
}
