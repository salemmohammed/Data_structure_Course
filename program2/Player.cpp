



#include "Player.h"



Player::Player(std::string name, int budget)
{
    m_name = name;
    m_budget = budget;
}



std::string Player::getName()
{
    return m_name;
}

int Player::getBudget()
{
    return m_budget;
}


bool Player::bet(int amount)
{
    m_budget -= amount;
    return false;
}


void Player::collectWinnings(int amount)
{
    m_budget += amount;
}

