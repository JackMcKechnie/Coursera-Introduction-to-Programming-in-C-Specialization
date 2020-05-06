#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //Function that adds ".counts" to the end of the filename that is inputted

  //Use mallloc to initialise a string big enough to hold the filename and ".counts
  char * outstr = malloc((strlen(inputName) + 8) * sizeof(*inputName));
  //Copy the inputName into the outstr
  strcpy(outstr,inputName);
  //Concatenate ".counts" to the inputName
  strcat(outstr,".counts");
  //Return outstr
  return outstr;
  
}
