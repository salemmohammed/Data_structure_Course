target: lab7

lab7: lab7.o BSTree.o
	g++ lab7.o BSTree.o -o lab7
lab7.o: lab7.cpp
	g++ -c lab7.cpp
BSTree.o: BSTree.cpp
	g++ -c BSTree.cpp
clear:
	rm -rf *.o lab7
