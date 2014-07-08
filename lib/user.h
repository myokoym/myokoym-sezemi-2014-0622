#ifndef USER_H
#define USER_H

#define USER_RECIPES_SIZE 256

#include "recipe.h"

typedef struct _user {
  int    id;
  char   *name;
  int    n_recipes;
  Recipe *recipes[USER_RECIPES_SIZE];
} User;

Recipe *user_get_recipe_by_id(User *, int);

#endif /* USER_H */
