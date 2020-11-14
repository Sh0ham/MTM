#define _CRT_SECURE_NO_WARNINGS
#define NUM 3
#include <stdio.h>
#include <math.h>

typedef struct Complex //Structures declaration
{
  float x;
  float yi;
}Complex;

float CRadius(Complex Complex); //Function declaration
Complex* Cmax(Complex arr[]);

int main()
{
  int itt = 0; //Variables declaration
  struct Complex arr[NUM]; //Array of complex numbers structure
  struct Complex* ptr; //Pointer to Complex type variables
  printf("Enter %d complex numbers:\n", NUM); //Retrieving data
  for (; itt < NUM; itt++)
  {
    scanf("%f %f", &arr[itt].x, &arr[itt].yi);
  }
  ptr = Cmax(arr);
  printf("\nThe max complex number is: %.2f+%.2fi", ptr->x, ptr->yi); //Printing result
  printf("\nThe radius of the max number is %.2f", CRadius(*ptr));
  return 0;
}

/*Function name: CRadius
Input: Complex number structure
Output: Numer's radius
Algorithm: Square root of it's sum of powers*/
float CRadius(Complex Complex)
{
  return sqrt(pow(Complex.x, 2) + pow(Complex.yi, 2)); //Return result
}

/*Function name: Cmax
Input: Array of complex numbers structure
Output: Pointer to the max compelx number available
Algorithm: Running on every slot of the array to find the maximum radius*/
Complex* Cmax(Complex arr[])
{
  int itt = 0; //Function variables
  float max;
  struct Complex* ptr;
  max = CRadius(arr[itt]); //Starting point set to first slot
  ptr = &arr[itt]; //Setting pointer to the first slot
  for (; itt < NUM; itt++) //Running with for loop on each slot
  {
    max < CRadius(arr[itt]) ? ptr = &arr[itt] : 0; //Updating pointer
    max = CRadius(arr[itt]); //Updating max variable
  }
  return ptr;
}
