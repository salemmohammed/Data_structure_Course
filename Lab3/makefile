all: lab3

lab3: lab3.o MovieChart.o
	g++ lab3.o MovieChart.o -o lab3
lab3.o: lab3.cpp
	g++ -c lab3.cpp
User.o: MovieChart.cpp
	g++ -c MovieChart.cpp
clean:
	rm -f *.o lab2