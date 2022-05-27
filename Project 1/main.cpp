#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "deckofcards.h"
using namespace std;


bool match();

int main(){
   srand(time(0));
// 1. most wins
   int p1wins(0);
   int p2wins(0);
   int wins = p1wins>p2wins?p1wins:p2wins;
// 2. avg scores
   int p1score(0);
   int p2score(0);
// 3. avg score winningest player
   int winnersAvg = p1wins>p2wins?p1score/100:p2score/100;
// 4. avg numCards() of losing player through all games
   int losersCards = 0; // increment after each iteration of while loop
//    end metrics variables
//   for(int i = 0; i <100; i++){
      Deck p1;// = new Deck();
      Deck p2;// = new  Deck();
      Deck battleground;// = new Deck();

// PRECONDITIONS: deck is of length 52

// after all decks are instantiated we must:
// 1.   fill battleground with all 52 cards | DONE
// 2.   shuffle the battleground
// 3.   deal half the deck to p1
// 4.   assign remaining deck to p2
// 5.   ensure battleground is clear
// 6.   begin war

/// (1)
      for(int j = 0; j < 5; j++){
	for(int k = 0; k < 14; k++){
	   Card dealt(j,k);
	   battleground.addCard(dealt);
	}
      }
/// (2)
      battleground.shuffle();
/// (3) & (4)
      while(sizeof(battleground)>0){
	p1.addCard(battleground.dealCard());
	p2.addCard(battleground.dealCard());
      }
/// (5)
      cout << "after shuffle" << endl;
      cout << "cards in battleground: " << battleground.numCards() << endl;
      cout << "p1 hand: " << p1.numCards() << " cards" << endl;
      cout << "p2 hand: " << p2.numCards() << " cards" << endl;
//      while(p1.numCards() > 0 && p2.numCards() > 0){
// consider implementing a check() function to see if card played matches top of battleground
// p1 makes first move
//      battleground.addCard(p1.dealCard());
// p2 makes second move
//      battleground.addCard(p2.dealCard());
//check for match
//        if(match(battleground[top].getFace(), battleground[top-1].getFace()) 
//      }
//   delete p1;
//   delete p2;
//   delete battleground;
   return 0;
}

bool match(string a, string b){
   return a.compare(b) == 0;
}
