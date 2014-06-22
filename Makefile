CC   = gcc
OBJS = recipe.o user.o main.o

recipe: $(OBJS)
	$(CC) -Wall -o $@ $(OBJS)

.c.o:
	$(CC) -Wall -c $<
