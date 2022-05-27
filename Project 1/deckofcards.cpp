#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "deckofcards.h"
//#include "card.h"

using namespace std;

//srand(time(0));
//constructor
// --> consider alternate constructor Deck(bool empty)
// 	true will return empty array, false will populate then shuffle the array (true by default); 
Deck::Deck() : top(-1), size(52), hand(new Card[size]) {} ;
//Deck::~Deck() { delete [] hand; };


// begin numCards()
int Deck::numCards() { return top+1; }
// end numCards()


// begin shuffle()
void Deck::shuffle() {
   for (int x = 0; x < top; x++){
      int rando = 1 + rand() % (top); // int x = a + rand() % (b-a+1) ... a =1 :. (b-a+1) = b 
      swap(hand[x], hand[rando]);
   }
}
// end shuffle


// begin dealCard()
// check if empty before dealing card in driver 
Card Deck::dealCard() { return hand[top--]; }
// end dealCard()


// begin addCard()
bool Deck::addCard(Card c) {
   if ( top == size-1 ) return false;
// PRECONDITIONS: hand is not full
   hand[++top] = c;
   return true;
}
// end addCard()


// begin mergeDecks()
bool Deck::mergeDecks(Deck * other, bool shuf){
   while (!other->isEmpty()) { this->addCard(other->dealCard()); }
   if(shuf) { this->shuffle(); }
   return true;
}
// end mergeDecks()

//begin displayCard()
Card Deck::displayCard(int x) { return hand[x]; } // why don't we make a void function that can cout hand[x].prettyCard()
// end displayCard()


// begin isEmpty()
bool Deck::isEmpty() { return top == -1; }
// end isEmpty()


//begin printDeck()
void Deck::printDeck() {
   cout << "current hand, in order:\n\n";
   for (int i = 0; i < sizeof(hand); i++){
      cout << hand[i].prettyCardName() << endl;
   }
}
// end printDeck()
