#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include "Deck.h"
#include "Player.h"

class Table
{
private:
    int num_seats;
    int ante;
    std::vector<Player> players;
    Deck deck;
    std::string lastWinner;

public:
    Table(int num_seats, int ante);
    ~Table();
    bool emptySeat();
    void addPlayer(Player p);
    std::vector<Player> playRound();
    void printWinner();
};

#endif