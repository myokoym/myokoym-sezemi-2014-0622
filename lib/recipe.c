#include "recipe.h"
#include <stdlib.h>

static int recipe_id = 1;

Recipe *
recipe_new() {
  Recipe *recipe;

  recipe = malloc(sizeof(*recipe));
  recipe->id = recipe_id;
  recipe_id++;

  return recipe;
}
