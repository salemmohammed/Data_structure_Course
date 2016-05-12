target: lab8

lab8: lab8.o Sort.o
	g++ lab8.o Sort.o -o lab8
lab8.o: lab8.cpp
	g++ -std=c++11 -c lab8.cpp
Sort.o: Sort.cpp
	g++ -std=c++11 -c Sort.cpp
clear:
	rm -rf *.o lab8
