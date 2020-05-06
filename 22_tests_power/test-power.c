#include <stdlib.h>
#include <stdio.h>


unsigned power(unsigned x, unsigned y);

int main(){
  //Test cases

  //Test for 0^0 = 1
  if (power(0,0) != 1){
    printf("Failed on testing 0^0=1\n");
    return EXIT_FAILURE;
  }

  //Test for 0^1 = 0
  if (power(0,1) != 0){
    printf("Failed on testing 0^1=0\n");
    return EXIT_FAILURE;
  }

  //Test for 0^31 = 0
  if (power(0,31) != 0){
    printf("Failed on testing 0^31=0\n");
    return EXIT_FAILURE;
  }
  
  //Test for 1^0 = 1
  if (power(1,0) != 1){
    printf("Failed on testing 1^0=1\n");
    return EXIT_FAILURE;
  }
  
  //Test for 31^0 = 1
  if (power(31,0) != 1){
    printf("Failed on testing 31^0=1\n");
    return EXIT_FAILURE;
  }
  
  //Test for 1^0 = 1
  if (power(1,0) != 1){
    printf("Failed on testing 1^0=1\n");
    return EXIT_FAILURE;
  }
  
  //Test for 1^31 =1
  if (power(1,31) != 1){
    printf("Failed on testing 1^31=1\n");
    return EXIT_FAILURE;
  }
  
  //Test for 2^3 = 8
  if (power(2,3) != 8){
    printf("Failed on testing 2^3=8\n");
    return EXIT_FAILURE;
  }
  
  //Test for 5^4 = 625
  if (power(5,4) != 625){
    printf("Failed on testing 5^4=625\n");
    return EXIT_FAILURE;
  }
  
  //Test for 77^1 = 77
  if (power(77,1) != 77){
    printf("Failed on testing 77^1=77\n");
    return EXIT_FAILURE;
  }
  
  //Test for 4^4 = 256
  if (power(4,4) != 256){
    printf("Failed on testing 4^4=256\n");
    return EXIT_FAILURE;
  }
  
  //Test for 1^1 = 1
  if (power(1,1) != 1){
    printf("Failed on testing 1^1=1\n");
    return EXIT_FAILURE;
  }
  
  //Test for -1^0 = 1
  if (power(-1,0) != 1){
    printf("Failed on testing -1^0=1\n");
    return EXIT_FAILURE;
  }
  
  //Test for 0^-1 = 0
  if (power(0,-1) != 0){
    printf("Failed on testing 0^-1=0\n");
    return EXIT_FAILURE;
  }
  
  //Test for 2^31 = 2147483648
  if(power(2,31) != 2147483648){
    printf("Failed on testing 2^31\n");
    return EXIT_FAILURE;
  }
  
  //Passes test cases
  return EXIT_SUCCESS;
}
