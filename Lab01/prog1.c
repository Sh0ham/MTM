#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 10

int main()
{
  int itt, Arr[SIZE]={3,5,10,1,2,7,6,9,0,8}; //Program variables
  int** Parr;
  assert(Parr = (int**)malloc(SIZE * sizeof(int*))); //Initializing pointers array
  for (itt = 0; itt < SIZE; itt++) //Setting addresses of arrays slots
  {
    Parr[itt] = &Arr[itt];
  }
  printf("My Array is: ");
  for (itt = SIZE-1; itt >= 0; itt--) //Printing backward each value of arr
  {
    printf("%d ", *Parr[itt]);
  }
  free(Parr); //Release memory allocated by the program
  return 0;
}
