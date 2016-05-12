all: lab4

lab4: lab4.o LinkedList.o
	g++ lab4.o LinkedList.o -o lab4
lab4.o: lab4.cpp
	g++ -c lab4.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
clean:
	rm -f *.o lab4