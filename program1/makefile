all: program1

program1: program1.o MovieChart.o
	g++ program1.o MovieChart.o -o program1
program1.o: program1.cpp
	g++ -c program1.cpp
MovieChart.o: MovieChart.cpp
	g++ -c MovieChart.cpp
clean:
	rm -f *.o program1
