all: lab5

lab5: lab5.o Card.o Deck.o
	g++ lab5.o Card.o Deck.o -o lab5
lab5.o: lab5.cpp
	g++ -c lab5.cpp
Cards.o: Card.cpp
	g++ -c Card.cpp
Deck.o: Deck.cpp
	g++ -c Deck.cpp
clean:
	rm -f *.o lab5
