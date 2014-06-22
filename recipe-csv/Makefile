CC       = gcc
OBJS     = recipe-csv.o

recipe-csv: $(OBJS)
	$(CC) -L../ -o ../$@ $(OBJS) -lrecipe

.c.o:
	$(CC) -c $<
