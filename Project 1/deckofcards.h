#ifndef DECK_OF_CARDS
#define DECK_OF_CARDS

using namespace std;
#include "card.h"

class Deck {
   private:
      // Fill in with what you need. Hint: It's an array!
      int size;
      Card * hand;
      int top;

   public:
      // Class management
      Deck();
//      ~Deck(); // NEED DESTRUCTOR ??
      // readCards(string);         // read in cards from a file
      
      // Key class functionality
      void shuffle();             // any sufficiently random sort with at least 3n random swaps is fine
      Card dealCard();            // deal the top card of the deck and remove it from the deck
      bool addCard(Card);            // append card to deck if there is space, fail otherwise
      bool mergeDecks(Deck *, bool);   // add cards from input to this deck, then empty the input deck. bool for shuffle afterwards (default = false)
      int numCards();
      // Display functions
      Card displayCard(int);         // displays the ith card of the deck
      bool isEmpty();               // returns whether or not the deck is empty
      void printDeck();            // print a nicely formatted list of the cards in deck order
};

#endif
