#include <iostream>
#include "Table.h"

#include <random>

using namespace std;

Table::Table(int num_seats, int ante){
    this->num_seats = num_seats;
    this->ante = ante;
}

Table::~Table(){ }

void Table::addPlayer(Player player){
    if(this->players.size() < this->num_seats)
    {
        this->players.push_back(player);
    }
}

bool Table::emptySeat(){
    return players.size() < num_seats;
}

std::vector<Player> Table::playRound()
{
    if (players.size() == 0)
        return std::vector<Player>();

    ///"The 52 cards in the deck are shuffled (randomized)."
    deck = Deck();
    deck.shuffle();

    ///"Each player ante’s (puts in a minimum bet)"
    for (auto player : players)
    {
        player.bet(ante);
    }

    std::vector<Card> player_cards;

    ///"Then each player is given one card from the top of the deck"
    for (auto player : players){
        auto card = deck.draw();
        player_cards.push_back(card);
    }

    std::size_t winner_index = std::rand() % players.size();

    std::vector<Player> losers;

    int total_winnings = 0;
    for (std::size_t player_index = 0; player_index < players.size(); ++player_index)
    {

        if (player_index == winner_index)
            continue;

        total_winnings += ante;
        losers.push_back(players[player_index]);
    }

    ///QUESTION: WHAT DOES THE WINNER WIN???
    players[winner_index].collectWinnings(total_winnings);

    lastWinner = players[winner_index].getName();

    players.clear();

    return losers;
}

void Table::printWinner()
{
    std::cout << lastWinner << std::endl;
}




