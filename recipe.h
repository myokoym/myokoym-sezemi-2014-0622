#ifndef RECIPE_H
#define RECIPE_H

#define RECIPE_NAME_SIZE 256
#define RECIPE_URL_SIZE 256

typedef struct {
  char name[RECIPE_NAME_SIZE];
  char url[RECIPE_URL_SIZE];
} Recipe;

int recipe_print(Recipe *, int);

#endif /* RECIPE_H */
