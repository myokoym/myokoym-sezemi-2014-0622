CC   = gcc
OBJS = recipe.o main.o

recipe: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<
