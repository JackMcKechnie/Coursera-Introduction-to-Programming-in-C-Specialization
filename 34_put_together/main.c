#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //Create a counts_t to store answer in
  counts_t * answer = createCounts();

  //Open the file
  FILE * file = fopen(filename,"r");
  if(file == NULL){
    return NULL;
  }

  //Set up appropriate variables and loop through each line in the file 
  char * line = NULL;
  size_t sz = 0;

  while(getline(&line,&sz,file) >= 0){
    //Change newline character to null terminator character
    char * newline = strchr(line,'\n');
    if(newline != NULL){
      *newline = '\0';
    }

    //Add a count for the key/value pairs in the line
    addCount(answer,lookupValue(kvPairs,line));
  }

  //Clean up and close
  free(line);
  if(fclose(file) !=0){
    return NULL;
  }
  return answer;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)

  if(argc < 3){
    fprintf(stderr,"Error - invalid number of arguments given\n");
    return EXIT_FAILURE;
  }
  
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kvpairs = readKVs(argv[1]);
  //count from 2 to argc (call the number you count i)
  for(int i=2;i<argc;i++){

    //count the values that appear in the file named by argv[i], using kv as the
    //key/value pair
    //(call this result c)
    counts_t * c = countFile(argv[i],kvpairs);

    //compute the output file name from argv[i] (call this outName)
    char *  outName = computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE * f = fopen(outName,"w");
    if(f == NULL){
      perror("fopen");
      fprintf(stderr,"Error when opening %s\n",outName);
      abort();
    }
    
    //print the counts from c into the FILE f
    printCounts(c,f);

    //close f
    fclose(f);

    //free the memory for outName and c
    free(outName);
    freeCounts(c);

  }

  //free the memory for kv
  freeKVs(kvpairs);
   
  return EXIT_SUCCESS;
}
