#ifndef RECIPE_H
#define RECIPE_H

#define RECIPE_NAME_SIZE 256
#define RECIPE_URL_SIZE 256

typedef struct {
  int  id;
  char name[RECIPE_NAME_SIZE];
  char url[RECIPE_URL_SIZE];
} Recipe;

int recipe_print(Recipe *);

#endif /* RECIPE_H */
