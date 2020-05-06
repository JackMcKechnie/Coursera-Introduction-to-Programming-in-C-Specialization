#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement (int startAge,double initial,retire_info working,retire_info retired){

  double balance = initial;
  int totalMonths = startAge - 1;

  //Calculate working
  for (int i=0;i<working.months;i++){
    totalMonths++;
    printf("Age %3d month %2d you have $%.2f\n",totalMonths/12,totalMonths%12,balance);
    double toBeAdded = 0;
    toBeAdded = balance * ((working.rate_of_return/100)/12);
    balance = balance + working.contribution + toBeAdded;
  }

  //Calculate retired
  for (int i=0;i<retired.months;i++){
    totalMonths++;
    printf("Age %3d month %2d you have $%.2f\n",totalMonths/12,totalMonths%12,balance);
    double toBeAdded = 0;
    toBeAdded = balance * ((retired.rate_of_return/100)/12);
    balance = balance + retired.contribution + toBeAdded;
  }
  
}
  

  
int main(){
  retire_info working = {489,1000.0,4.5};
  retire_info retired = {384,-4000,1.0};
  retirement(327,21345,working,retired);
  return 0;
}    
    
  
