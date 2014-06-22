CC   = gcc
OBJS = user.o recipe.o

recipe: $(OBJS)
	$(CC) -shared -o ../$@.dll $(OBJS)

.c.o:
	$(CC) -c $<
