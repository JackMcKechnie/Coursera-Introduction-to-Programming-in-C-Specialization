#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "cards.h"
#include "future.h"

void add_future_card(future_cards_t *fc, size_t index,card_t *ptr){
  //If the unknown card is already in the future cards decks
  if(index < fc->n_decks){
    //Enlarge the array of this unknown card  by 1 
    fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*(fc->decks[index].cards)));
    //Point the last count of this unknown card to the placeholder card
    fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
    //Update the counter of this unknown card
    fc->decks[index].n_cards++;
  } else {
    //If the unknown card is not in the future cards decks
    while(fc->n_decks <= index){
      //Increase the size of decks by 1
      fc->decks = realloc(fc->decks,(fc->n_decks+1)*sizeof(*fc->decks));
      //Set the new deck, card deck to null
      fc->decks[fc->n_decks].cards = NULL;
      //Set the new deck card count to 0
      fc->decks[fc->n_decks].n_cards = 0;
      //Update the size of future cards by 1
      fc->n_decks++;
    }
    //Update the size of the decks by 1
    fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*(fc->decks[index].cards)));
    //Set the last count of this unkown card to ptr
    fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
    //Update the size of the deck for this unknown card
    fc->decks[index].n_cards++;
  }
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  //Error checking
  if(deck->n_cards<fc->n_decks){
    fprintf(stderr,"Invalid deck size in future_cards_from_deck\n");
    return;
  }
  
  //Loop over ever unknown card
  for(int i=0;i<fc->n_decks;i++){
    //If there is none left of this unknown card then skip
    if(fc->decks[i].n_cards == 0){
      continue;
    }
    //Loop over ever instance of this unknown card
    for(int j=0;j<fc->decks[i].n_cards;j++){
      //Set this unknown card to the appropriate card in the passed deck
      (*(fc->decks[i].cards[j])).value = (*(deck->cards[i])).value;
      (*(fc->decks[i].cards[j])).suit = (*(deck->cards[i])).suit;
    }
  }
}
  
