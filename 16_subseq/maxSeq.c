#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n){
  int run = 1;
  int largest = 1;
  
  if (n==0){
    return 0;
  }
  
  for (int i=1;i<n;i++){
    if(array[i] > array[i-1]){
      run++;
    }
    else{
      run = 1;
    }

    if(run > largest){
      largest = run;
    }
  }
  
  return largest;
}

    
    
    
