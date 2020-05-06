#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "counts.h"

counts_t * createCounts(void) {
  counts_t * counts = malloc(sizeof(*counts));
  counts->counts = NULL;
  counts->nCounts = 0;
  return counts;
}

one_count_t * createCount(const char * name){
  //Helper function to make a one_count_t given a name
  one_count_t * answer = malloc(sizeof(*answer));
  if(name != NULL){
    answer->name = strdup(name);//Must free
    assert(strcmp(name,answer->name) == 0);
  } else {
    answer->name = NULL;
  }
  answer->count = 1;
  return answer;
}
void addCount(counts_t * c, const char * name) {
  //Loop oven all counts in c
  for(int i=0;i<c->nCounts;i++){
    //If the name is unknown
    if(name == NULL){
      //If the current count is unknown
      if(c->counts[i]->name == NULL){
	//Increase unknown by 1
	c->counts[i]->count++;
	return;
      }
      //If the name is not null and already in counts
    } else if(c->counts[i]->name != NULL && strcmp(c->counts[i]->name,name) == 0){
      //Increase count of name by 1
      c->counts[i]->count++;
      return;
    }
  }

  //If name is not in counts
  c->nCounts++;
  c->counts = realloc(c->counts,c->nCounts*sizeof(c->counts));
  c->counts[c->nCounts - 1] = createCount(name);
}
void printCounts(counts_t * c, FILE * outFile) {
  int unknownIndex = -1;
  //Loop over all counts in c
  for(int i=0;i<c->nCounts;i++){
    //If current name is NULL, take note of its index as we will print this later
    if(c->counts[i]->name == NULL){
      unknownIndex = i;
    } else {
      fprintf(outFile,"%s: %d\n",c->counts[i]->name,c->counts[i]->count);
    }
  }

  //Print out unknowns
  //If unknownIndex != -1 then we have unknowns to print
  if (unknownIndex != -1){
    fprintf(outFile,"<unknown>: %d\n",c->counts[unknownIndex]->count);
  }
}

void freeCounts(counts_t * c) {
  for(int i=0;i<c->nCounts;i++){
    free(c->counts[i]->name);
    free(c->counts[i]);
  }
  free(c->counts);
  free(c);
}
