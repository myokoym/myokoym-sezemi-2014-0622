CC       = gcc
OBJS     = recipe.o

recipe: $(OBJS)
	$(CC) -L../ -o ../$@ $(OBJS) -lrecipe

.c.o:
	$(CC) -c $<
