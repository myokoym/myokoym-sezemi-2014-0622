#ifndef USER_H
#define USER_H

#define USER_RECIPES_SIZE 256

#include "recipe.h"

typedef struct {
  char *name;
  Recipe recipes[USER_RECIPES_SIZE];
} User;

void user_print_name(User *);
int user_scan_from_file(User *, char *);
void user_print_all(User *);
int user_print_with_id(User *, int);

#endif /* USER_H */
