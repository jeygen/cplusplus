# Makes all by default, if specifiy then makes target

# Set the C++ compiler to g++
CC=g++

# Set compilation flags for g++. In this case:
# -Wall enables all compiler's warning messages
# -std=c++11 sets the C++ version to C++11
CFLAGS=-Wall -std=c++11

# Find all .cpp files in the current directory
SOURCES=$(wildcard *.cpp)

# Remove the file extension from all source files
BINARIES=$(patsubst %.cpp,%,$(SOURCES))

# Default target executed when no arguments are given to make.
# It will compile all .cpp files and create an executable for each one.
all: $(BINARIES)

# Rule for building a single target.
# The automatic variables $@ and $< represent the target name and the
# first prerequisite respectively.
%: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

        


