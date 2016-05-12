target: lab6

lab6: lab6.o BSTree.o
	gcc lab6.o BSTree.o -o lab6
lab6.o: lab6.cpp
	gcc -c lab6.cpp
BSTree.o: BSTree.cpp
	gcc -c BSTree.cpp
clear:
	rm -rf *.o lab6
