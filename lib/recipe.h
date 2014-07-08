#ifndef RECIPE_H
#define RECIPE_H

#define RECIPE_NAME_SIZE 256
#define RECIPE_URL_SIZE 256

typedef struct _recipe {
  int  id;
  char name[RECIPE_NAME_SIZE];
  char url[RECIPE_URL_SIZE];
} Recipe;

Recipe *recipe_new();

#endif /* RECIPE_H */
