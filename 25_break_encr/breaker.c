#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Program to break a ceaser cipher using frequency counting

void  frequencyOfChars(FILE * file,int frequencies[]){
  int currChar;
  while((currChar = fgetc(file)) != EOF){
    if(isalpha(currChar)){
      currChar = tolower(currChar);
      currChar -= 'a';
      frequencies[currChar]++;
    }
  }
}

int calcKey(int frequencies[]){
  //Loop through the array and find index of largest value
  int maxIdx = 0;
  for(int i=0;i<26;i++){
    if(frequencies[i] > frequencies[maxIdx]){
      maxIdx = i;
    }
  }

  int key = 0;
  
  if(maxIdx >= ('e'-'a')){
    key = maxIdx - ('e'-'a');
  }
  else {
    key = (26-('e'-'a')) + maxIdx;
  }

  return key;	    
}

int main(int argc, char ** argv){
  //Error handling code - checking number of command line arguments
  if(argc != 2){
    fprintf(stderr,"Wrong number of command line arguments\n");
    return EXIT_FAILURE;
  }
  
  //Read in file
  FILE * file = fopen(argv[1],"r");

  //Error handling code - checking file is valid
  if(file == NULL){
    perror("File is not valid\n");
    return EXIT_FAILURE;
  }

  //Count the frequency of characters
  int frequencies[26] = {0};
  frequencyOfChars(file,frequencies);

  //Calculate key from most frequencies
  int key = calcKey(frequencies);

  printf("%d\n",key);

  //Error handling code - making sure file is closed
  if(fclose(file) != 0){
    perror("Failed to close the file\n");
    return EXIT_FAILURE;
  }
}
