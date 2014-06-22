CC       = gcc
LIB_OBJS = user.o recipe.o
OBJS     = main.o
DLL_NAME = librecipe

recipe: $(OBJS) $(DLL_NAME)
	$(CC) -o $@ $(OBJS) -L./ -l$(DLL_NAME)

$(DLL_NAME): $(LIB_OBJS)
	$(CC) -shared -o $@.dll $(LIB_OBJS)

.c.o:
	$(CC) -c $<
