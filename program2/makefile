all: program2

program2: program2.o Card.o Deck.o Heap.o Player.o Table.o
	g++ program2.o Card.o Deck.o Heap.o Player.o Table.o -o program2
program2.o: program2.cpp
	g++ -c program2.cpp -std=c++11
Card.o: Card.cpp
	g++ -c Card.cpp -std=c++11
Deck.o: Deck.cpp
	g++ -c Deck.cpp -std=c++11
Heap.o: Heap.cpp
	g++ -c Heap.cpp -std=c++11
Player.o: Player.cpp
	g++ -c Player.cpp -std=c++11
Table.o: Table.cpp
	g++ -c Table.cpp -std=c++11
clean:
	rm -f *.o program2
