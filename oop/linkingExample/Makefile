CC=g++ # compiler choice
CFLAGS=-I. # this flag means look in current dir
DEPS = person.h
OBJ = person.o main.o

%.o: %.cpp $(DEPS) # any .o depends on .cpp and DEPs files
	$(CC) -c -o $@ $< $(CFLAGS) # what it will do

main: $(OBJ) # what main depends on
	$(CC) -o $@ $^ $(CFLAGS) # what it will do

# $@ is Makefile slang for target of rule, so main in main
# $^ is Makefile slang for dependency of rule, so $(OBJ) in main:
# 
# Makefile or makefile work, but Makefile is convetion name
#
# use make to make

