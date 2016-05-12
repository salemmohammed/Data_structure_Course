all: program3

program3: program3.o Map.o City.o
	g++ program3.o Map.o City.o -o program3
program3.o: program3.cpp
	g++ -c program3.cpp -std=c++11
Map.o: Map.cpp
	g++ -c Map.cpp -std=c++11
City.o: City.cpp
	g++ -c City.cpp -std=c++11

clean:
	rm -f *.o program3