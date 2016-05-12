// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <cassert>

#include "Deck.h"

Deck::Deck(){
  // Fill the deck with cards:
  for ( unsigned value = 1; value <= 13; ++value )
    for ( unsigned suit = 1; suit <= 4; ++suit )
      mCards.push_back( Card( suit, value) );
}

Deck::~Deck(){

}

void Deck::shuffle() {
    // Shuffles the deck (even when there are cards missing)
    std::random_shuffle( mCards.begin(), mCards.end() );
}

void Deck::print()
{
  for (std::deque<Card>::iterator w = mCards.begin(); w != mCards.end(); ++w)
  {
    w->print();
    std::cout << " ";
  }
  std::cout << std::endl;
}

int Deck::size() const {
  return mCards.size();
}

Card Deck::draw() {
  assert(mCards.size() > 0);

  //get the last card in the deck
  Card c = mCards.back();
  //pop the last card in the deck
  mCards.pop_back();
  return c;
}
