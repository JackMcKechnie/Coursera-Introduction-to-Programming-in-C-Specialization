#include <stdlib.h>
#include <stdio.h>

unsigned power(unsigned x, unsigned y){
  //Special base case of 0^0 = 1
  if (x == 0 && y == 0){
    return 1;
  }

  //Base case x = 0
  if(x==0){
    return 0;
  }

  //Base case x = 1 and y = 1
  if(x==1 || y==0){
    return 1;
  }

  return x * power(x,y-1);
}
