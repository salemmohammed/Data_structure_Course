#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
    public:
        int Card_hand;
        Player(std::string name, int budget);
        std::string getName();
        int getBudget();
        bool bet(int amount); 
        //Removes a specified amount of money from the player’s budget
        void collectWinnings(int amount);
        // Adds a specified amount of money to the player’s budget
    private:
        std::string m_name;
        int m_budget;
};

#endif 