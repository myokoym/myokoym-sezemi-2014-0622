CC   = gcc
OBJS = recipe.o user.o main.o

recipe: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<
