#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rotate.c"

void rotate(char matrix[10][10]);

/*
void readIn(FILE *file, char matrix[10][10]){
  //Reads the file into the array
  char c;
  c = fgetc(file);
  while(c != EOF){
    printf("%d",c);
    c = fgetc(file);
  }
}

void printMatrix(char matrix[10][10]){
  //Prints out the 10x10 matrix

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      printf("%c",matrix[i][j]);
    }
    printf("\n");
  } 
}

*/
int main(int argc, char *argv[]){
  /* Program that:
                   Reads in a 10x10 matrix into a 10x10 array
		   Rotates the 10x0 matrix
		   Prints out the 10x10 matrix */

  //ERROR CHECKING CODE - Check that there is the correct number of command line args
  if(argc != 2){
    fprintf(stderr,"Invalid number of arguments given\n");
    return EXIT_FAILURE;
  }

  //Open the file
  FILE * file = fopen(argv[1],"r");

  //ERROR CHECKING CODE - Check that the file is valid
  if(file == NULL){
    perror("Invalid file, could not open\n");
    return EXIT_FAILURE;
  }

  int height = 0;
  char line[12];
  char matrix[10][10];

  while(fgets(line,12,file) != NULL){
    
    //If line has more than 10 characters
    if(strchr(line,'\n') == NULL){
      fprintf(stderr,"Input line %d has too many characters\n",height);
      return EXIT_FAILURE;
    }

    //If line has les than 10 characters
    int whereIsNL = 0;
    for(int n=0;n<12;n++){
      if(line[n] == '\n'){
	whereIsNL = n;
      }
    }

    if(whereIsNL < 10){
      fprintf(stderr,"Input line %d is too small\n",height);
      return EXIT_FAILURE;
    }

    for(int i=0;i<10;i++){
      matrix[height][i] = line[i];
    }

    height++;
    
  }

  //If matrix has less than 10 rows
  if(height<10){
    fprintf(stderr,"Input height is too small\n");
    return EXIT_FAILURE;
  }


  //If matrix has more than 10 rows
  if(height > 10){
    fprintf(stderr,"Input height is too big\n");
    return EXIT_FAILURE;
  }
  
  //If file doesn't close
  if(fclose(file) != 0){
    perror("Failed to close file\n");
    return EXIT_FAILURE;
  }
  
  //Call rotateMatrix to rotate the matrix by 90 degrees
  rotate(matrix);

  //Print matrix
  for(int r=0;r<10;r++){
    for(int c=0;c<10;c++){
      printf("%c",matrix[r][c]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
