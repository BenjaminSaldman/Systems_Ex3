CC=gcc
AR=ar
OBJECTS_MAIN=stringProg.o
OBJECTS_LIB=helper.o
FLAGS= -Wall -g
all: stringProg
stringProg: $(OBJECTS_MAIN) $(OBJECTS_LIB)
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) $(OBJECTS_LIB)
stringProg.o: stringProg.c strings.h
	$(CC) $(FLAGS) -c stringProg.c
helper.o: helper.c strings.h
	$(CC) $(FLAGS) -c helper.c
.PHONY: clean all
clean:
	rm -f *.o *.a *.so stringProg 