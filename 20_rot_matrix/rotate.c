#include <stdlib.h>
#include <stdio.h>

void rotate(char matrix [10][10]){
  //Create matrix put result in
  char out [10][10];

  //Loop through the arrays in matrix
  for(int i=0;i<10;i++){
    //Loop through current array
    for (int j=0;j<10;j++){
      //Fill current array backwards
      out[j][9-i] = matrix[i][j];
    }
  }

  //Copy result into original matrix
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      matrix[i][j] = out[i][j];
    }
  }
}


    
    
