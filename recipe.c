#include "recipe.h"
#include <stdio.h>
#include <stdlib.h>

static int recipe_id = 1;

Recipe *
recipe_new() {
  Recipe *recipe;
  recipe = (Recipe *)malloc(sizeof(*recipe));
  recipe->id = recipe_id;
  recipe_id++;
  return recipe;
}

int
recipe_print(Recipe *recipe) {
  printf("%d: %s %s\n", recipe->id, recipe->name, recipe->url);
  return 0;
}
