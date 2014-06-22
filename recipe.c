#include "recipe.h"
#include <stdio.h>

int
recipe_print(Recipe *recipe, int id) {
  printf("%d: %s %s\n", id, recipe->name, recipe->url);
  return 0;
}
