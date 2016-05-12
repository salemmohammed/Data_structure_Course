all: lab2

lab2: lab2.o User.o
	g++ lab2.o User.o -o lab2
lab2.o: lab2.cpp
	g++ -c lab2.cpp
User.o: User.cpp
	g++ -c User.cpp
clean:
	rm -f *.o lab2