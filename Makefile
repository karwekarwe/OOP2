CC = g++
CFLAGS = -Wall -std=c++17
TESTS = test/test_Vector.cpp test/catch_amalgamated.cpp vector/vector.h

.PHONY: all clean test

all: vector

vector: vector/3.0main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h vector/vector.h
	$(CC) $^ -o $@

test: $(TESTS)  vector/vector.h
	$(CC) $(CFLAGS) $^ -o tests
	./tests

clean:
	rm -f vector tests

