CXX=g++

.PHONY: all clean

all: main

main: main.o MovieCollection.o
	${CXX} main.o MovieCollection.o -o main

main.o: main.cpp Movie.hpp
	${CXX} -c main.cpp -o main.o

MovieCollection.o: MovieCollection.cpp MovieCollection.hpp
	${CXX} -c MovieCollection.cpp -o MovieCollection.o

clean:
	rm -f *.o main
