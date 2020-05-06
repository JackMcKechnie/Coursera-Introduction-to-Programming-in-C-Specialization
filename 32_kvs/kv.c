#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


kvpair_t * extractKV(char ** line){
  
  char * p = strchr(*line,'=');

  if(p == NULL){
    fprintf(stderr,"ERROR - Not a key value pair");
    return NULL;
  }

  kvpair_t *  answer =  malloc(sizeof(*answer));
  *p = '\0';
  answer->key = *line;
  p++;
  char * end = strchr(p,'\n');
  if(end != NULL){
    *end = '\0';
  }

  answer->value = p;

  return answer;
}


void addToArray(kvarray_t * answer,kvpair_t * KVPair){
  answer->numPairs++;
  answer->pairs = realloc(answer->pairs,answer->numPairs*sizeof(*answer->pairs));
  answer->pairs[answer->numPairs-1] = KVPair;
}

kvarray_t * readKVs(const char * fname) {
  //Reads key value pairs from the file into data structures

  //Open the file
  FILE * file = fopen(fname,"r");
  if (file == NULL){
    perror("Unable to open file\n");
    return NULL;
  }

  //Loop over each line
  char * line = NULL;
  size_t sz = 0;

  kvarray_t * answer = malloc(sizeof(*answer));
  answer->numPairs = 0;
  answer->pairs = NULL;

  
  while(getline(&line,&sz,file) != -1){

    //Extract key value pairs
    kvpair_t * KVPair = extractKV(&line);
  	   
    //Add the key value pairs to array
    // addToArray(answer,KVpair);
    
    answer->numPairs++;
    answer->pairs = realloc(answer->pairs,answer->numPairs*sizeof(*answer->pairs));
    answer->pairs[answer->numPairs-1] = KVPair;
    line = NULL;
  }
  
  //Clean up and return
  free(line);
  fclose(file);
  return answer;
}


void freeKVs(kvarray_t * pairs) {
  //Frees memory used by readKVs

  for(int i=0; i<pairs->numPairs;i++){
    free(pairs->pairs[i]->key);
    free(pairs->pairs[i]);
  }
  free(pairs->pairs);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //Print each key value pair in the format "key = 'XYZ' value = 'ABC'"

  for(int i=0;i<pairs->numPairs;i++){
    printf("key = '%s' value = '%s'\n",pairs->pairs[i]->key,pairs->pairs[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //Returns the value associated with the key passed in. If there is no match then NULL is returned

  for(int i=0;i<pairs->numPairs;i++){
    if(strcmp(pairs->pairs[i]->key,key)==0){
      return pairs->pairs[i]->value;
    }
  }

  return NULL;
}
