CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: v0 v1 v2 v3

v0: vector/1.1main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h
	$(CC) $^ -o $@

v1: vector/1.1main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h
	$(CC) $(CFLAGS) -O1 $^ -o $@

v2: vector/1.1main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h
	$(CC) $(CFLAGS) -O2 $^ -o $@

v3: vector/1.1main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h
	$(CC) $(CFLAGS) -O3 $^ -o $@

clean:
	rm -f v0 v1 v2 v3
