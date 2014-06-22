#ifndef RECIPE_H
#define RECIPE_H

#define ITEM_SIZE 256

typedef struct {
  char name[ITEM_SIZE];
} Recipe;

int validate_arguments(int);
int scan_from_file(char *, Recipe *);
void print_all(Recipe *);
int print_with_id(Recipe *, int);

#endif /* RECIPE_H */
