#include "card.h"

using namespace std;
// Move these two lines to your card.cpp file, after you've included card.h but before your functions.
string Card::suit[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
string Card::face[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
Card::Card() {};

Card::Card(int x, int y) {
   suit_val = x;
   face_val = y;
}

// getface()
string Card::getFace() { return face[face_val]; }

// getsuit()
string Card::getSuit() { return suit[suit_val]; }

// prettyname()
string Card::prettyCardName() { return getFace()+ " of " + getSuit();}
