#ifndef RECIPE_H
#define RECIPE_H

#define ITEM_SIZE 256

typedef struct {
  char name[ITEM_SIZE];
} Recipe;

int validate_arguments(int);
int scan(char *, Recipe *);
void print(Recipe *);

#endif /* RECIPE_H */
