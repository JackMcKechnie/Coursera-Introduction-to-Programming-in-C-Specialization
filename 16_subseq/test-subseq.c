#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array,size_t n);

int main(){
  int array1[] = {1,2,3,2};
  int array2[] = {2,-3,5,6,8};
  int array3[] = {5};
  int array4[] = {2,4,3,6,10,15,-1,7,8,2};
  int array5[] {-2};
  int array6[] = {2,2,2,3};

  //Test 1
  if(maxSeq(NULL,0)){
    printf("Failed on test 1 - {NULL}\n");
    return EXIT_FAILURE;
  }

  //Test 2
  if(maxSeq(array1,0)){
    printf("Failed on test 2 {1,2,3,2}\n");
    return EXIT_FAILURE;
  }

  //Test 3
  if(maxSeq(array1,4) != 3){
    printf("Failed on test 3 {1,2,3,2}\n");
    return EXIT_FAILURE;
  }

  //Test 4
  if(maxSeq(array2,5) != 4){
    printf("Failed on test 4 {2,-3,5,6,8}\n");
    return EXIT_FAILURE;
  }

  //Test 5
  if(maxSeq(array3,1) != 1){
    printf("Failed on test 5 {5}\n");
    return EXIT_FAILURE;
  }

  //Test 6
  if(maxSeq(array4,10) != 4){
    printf("Failed on test 6 {2,4,3,6,10,15,-1,7,8,2}\n");
    return EXIT_FAILURE;
  }

  //Test 7
  if(maxSeq(array5,1) != 1){
    printf("Failed on test 7 {-2}\n");
    return EXIT_FAILURE;
  }

  //Test 8
  if(maxSeq(array6,4) != 2){
    printf("Failed on test 8 {2,2,2,3}\n");
    return EXIT_FAILURE;
  }

  //Correct implementation
  return EXIT_SUCCESS;
}

