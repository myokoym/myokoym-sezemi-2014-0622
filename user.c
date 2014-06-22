#include "user.h"
#include <stdlib.h>

Recipe *
user_get_recipe_by_id(User *user, int id) {
  int i;

  for (i = 0; i < user->n_recipes; i++) {
    if (user->recipes[i]->id == id) {
      return user->recipes[i];
    }
  }

  return NULL;
}
