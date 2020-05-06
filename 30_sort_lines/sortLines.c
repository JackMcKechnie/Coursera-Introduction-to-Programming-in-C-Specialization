#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

//Function to sort lines
char ** sortLines(FILE * file, size_t * nitems){
  char * line = NULL;
  size_t sz = 0;
  char ** arr = NULL;
  size_t n = 0;

  while(getline(&line,&sz,file) >= 0){
    n++;
    arr = realloc(arr,n*sizeof(*arr));
    arr[n-1] = line;
    line = NULL;
  }
  
  free(line);

  sortData(arr,n);

  *nitems = n;

  return arr;
}
  
//Function to print sorted lines
void printLines(FILE * file){
  size_t n = 0;
  char ** arr = sortLines(file,&n);

  for(int i=0;i<n;i++){
    printf("%s",arr[i]);
    free(arr[i]);
  }
  free(arr);
}

int main(int argc, char ** argv) {

  if(argc == 1){
    printLines(stdin);
  }
  else if(argc>1) {
    for(int i=1;i<argc;i++){
      
      FILE * file = fopen(argv[i],"r");
      
      //ERROR CHECKING CODE - Making sure the file is valid
      if(file == NULL){
	perror("File invalid\n");
	return EXIT_FAILURE;
      }

      printLines(file);
      fclose(file);
    }
  }
  return EXIT_SUCCESS;
}
