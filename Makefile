# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Source directories
SRCDIRS = vector

# Object directories
OBJDIRS = $(SRCDIRS:%=%/obj)

# Executable names
EXEC = v

# Text file name
TXTFILES = studentai1000.txt studentai10000.txt studentai100000.txt studentai1000000.txt studentai10000000.txt

# Default target
all: $(EXEC)

# Build targets for each version of the program
v: vector/1.1main.o vector/isFailo.o vector/rusiavimasGen.o vector/papFunkcijos.o vector/failuGen.o 
	$(CC) $(CFLAGS) -O2 $^ -o $@

# Build rule for object files in each directory
%/obj/%.o: %/%.cpp %/funkcijos.h %/student.h
	$(CC) $(CFLAGS) -O2 -c $< -o $@

# Rule to copy the text file to the current directory
$(TXTFILES):
	cp $@ $(foreach exec,$(EXEC),$(dir $(exec)))

# Clean command
clean:
	rm -f $(foreach dir,$(OBJDIRS),$(wildcard $(dir)/*.o))
	rm -f $(EXEC)