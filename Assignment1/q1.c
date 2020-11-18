/**************************
*╔═╗╦═╗╔═╗╔═╗╔╦╗╦╔═╗╔╗╔╔═╗*
*╠╣ ╠╦╝╠═╣║   ║ ║║ ║║║║╚═╗*
*╚  ╩╚═╩ ╩╚═╝ ╩ ╩╚═╝╝╚╝╚═╝*
***************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct fraction //Structures declaration
{
  int numerator;
  int denominator;
}frac;

int data(frac *fracs); //Function declaration
void summarize(frac fracs[], int counter);

int main()
{
	frac *fracs; //Program variables
	assert(fracs = (frac*)malloc(1*sizeof(frac)));
  int counter = data(fracs); //Counting fracber of fractions by retrieving data from user
  summarize(fracs, counter); //Calculate the sum of fractions
  free(fracs);
  return 0;
}

/*Function name: data
Input: Array of fractions
Output: Amount of fractions
Algorithm: Counting each fraction was added*/
int data(frac *fracs)
{
  int counter = 0; //Function variables
  printf("Enter fractions by pairs of integers; Enter 0 0 to finish.\n");
  do
  {
    printf("Enter fraction number %d, numerator and denominator: ", (counter + 1)); //Asking user for input
    scanf("%d %d", &fracs[counter].numerator, &fracs[counter].denominator); //Reciving user's input
    while (fracs[counter].numerator == 0 && fracs[counter].denominator != 0) //Logic test for dividing by zero
    {
      rewind(stdin); //Reset input
      printf("Denominator can not be zero, try again: "); //Error message
      scanf("%d %d", &fracs[counter].numerator, &fracs[counter].denominator); //Getting valid fraction
    }
    (fracs[counter].numerator != 0) && (fracs[counter].denominator != 0) ? (counter++, fracs = (frac*)realloc(fracs, (counter+1) * sizeof(frac))) : 0; //Relocate memory for size of counter slots array
  }
  while(fracs[counter].numerator != 0 && fracs[counter].denominator != 0);
  return counter; //Sending back the amount of fractions
}
/*Function name: summarize
Input: Array of fractions and number of fractions
Output: None
Algorithm: Sum fractions and printing result*/
void summarize(frac fracs[], int counter)
{
  int numerator = 1, denominator = 1, sum = 0, itt, jtt, whole, fraction; //Function variables
  for (itt = 0; itt < counter; itt++) //Running with for loop on all frations
  {
    numerator = fracs[itt].numerator; //Setting function variables to data given
    denominator *= fracs[itt].denominator; //Calculate multiplication of all denominators
    itt+1 == counter ? printf("%d/%d = ", fracs[itt].numerator, fracs[itt].denominator) : printf("%d/%d + ", fracs[itt].numerator, fracs[itt].denominator); //String concatenation
    for (jtt = 0; jtt < counter; jtt++) //Running with for loop on all fractions except pivot
    {
      jtt != itt ? numerator *= fracs[jtt].denominator : 0; //Calculate multiplication of all denominators by numerator
    }
    sum += numerator; //Sum up all numerators after they multiplied by each denominator
  }
  whole = sum/denominator; //Calculate the whole part of the fraction
  fraction = sum%denominator; //Calculate the fractional part of the fraction
  for (itt = fraction; itt > 0; itt--) //Running with for loop on fractional part to minimize it
  {
    fraction%itt == 0 && denominator%itt == 0 ? (fraction /= itt, denominator /= itt, itt = 0) : 0; //Simplifying the fraction
  }
  printf("%d/%d = %d and %d/%d", whole*denominator+fraction, denominator, whole, fraction, denominator); //Printing result, before and after simplifying
}
