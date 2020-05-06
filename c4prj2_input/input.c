#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  //Function to convert a string into a deck_t

  //Create return deck
  deck_t * deck = malloc(sizeof(*deck));
  //Initialise return deck
  deck->cards = NULL;
  deck->n_cards = 0;

  //Loop through the string
  for(int i=0;i<strlen(str);i++){
    //Ignore spaces and newline characters
    if ((str[i] == '\n') || (str[i] == ' ')){
      continue;
    } else {
      //Deal with unknown cards
      if(str[i] == '?'){
	//Skip the ? to get to the index of the unknown card
	i++;
	//Copy the string into a new string to be passed to add_future_card
	char num[strlen(str)];
	int n = 0;
	while(!((str[i] == '\n') || (str[i] == ' '))){
	  num[n] = str[i];
	  i++;
	  n++;
	}
	num[n] = '\0';
	add_future_card(fc,atoi(num),add_empty_card(deck));
      } else {

	//Deal with known cards
	//Make the current card from the string
	card_t x = card_from_letters(str[i],str[i+1]);
	//Add this card to the return deck
	add_card_to(deck,x);
	i++;
      }
    }
  }
  //Error checking
  if(deck->n_cards < 5){
    fprintf(stderr,"Invalid number of cards in input");
    return NULL;
  }

  return deck;
}
	  
deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  //Array of decks to return
  deck_t ** arr = NULL;
  //Number of decks in the return array
  size_t n_hand = 0;

  //Setup for readline
  char * line = NULL;
  size_t sz = 0;

  //Loop through each line
  while(getline(&line,&sz,f) >= 0){
    //Increase the size of the return array by 1
    arr = realloc(arr,(n_hand+1) * sizeof(*arr));
    //Create deck from the hand held in the current line
    deck_t * deck = hand_from_string(line,fc);
    //If the line is empty deck will be null so skip
    if(deck == NULL){
      continue;
    }

    //Add the deck from this line to the return array
    arr[n_hand] = deck;
    //Update the number of hands
    n_hand++;
  }

  //Clean up from getline
  free(line);
  //Update the pointer to n_hands to be the number of hands in the input file
  *n_hands = n_hand;
  return arr;
}

