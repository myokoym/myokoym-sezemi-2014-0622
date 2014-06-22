#include "recipe.h"
#include <stdio.h>

int
recipe_print(Recipe *recipe) {
  printf("%d: %s %s\n", recipe->id, recipe->name, recipe->url);
  return 0;
}
