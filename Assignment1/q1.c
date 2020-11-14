/**************************
*╔═╗╦═╗╔═╗╔═╗╔╦╗╦╔═╗╔╗╔╔═╗*
*╠╣ ╠╦╝╠═╣║   ║ ║║ ║║║║╚═╗*
*╚  ╩╚═╩ ╩╚═╝ ╩ ╩╚═╝╝╚╝╚═╝*
***************************/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>

typedef struct fraction //Structures declaration
{
  int numerator;
  int denominator;
}num;

int data(num *fracs); //Function declaration
void summarize(num fracs[], int counter);

int main()
{
  num fracs[SIZE]; //Program variables
  int counter = data(fracs); //Counting number of fractions by retrieving data from user
  summarize(fracs, counter); //Calculate the sum of fractions
  return 0;
}

/*Function name: data
Input: Array of fractions
Output: Amount of fractions
Algorithm: Counting each fraction was added*/
int data(num *fracs)
{
  int itt = 0, counter = 0; //Function variables
  printf("Enter up to %d fractions, by pairs of integers; Enter 0 0 to finish.\n", SIZE-1);
  for (; itt < SIZE-1; itt++) //Retrieving fractions by user, each fraction for itteration
  {
    counter++; //Counting fractions
    printf("Enter fraction number %d, numerator and denominator: ", (itt+1)); //Asking user for input
    scanf("%d %d", &fracs[itt].numerator, &fracs[itt].denominator);
    if ((fracs[itt].denominator == 0) && (fracs[itt].numerator != 0)) //Logic test, can't divide by zero
    {
      do
      {
        rewind(stdin); //Reset input
        printf("Denominator can not be zero, try again: "); //Error message
        scanf("%d %d", &fracs[itt].numerator, &fracs[itt].denominator); //Getting valid fraction
      }
      while (fracs[itt].denominator == 0); //As long as the condition is true
     }
    else if (fracs[itt].numerator == 0 && fracs[itt].denominator == 0) //Exit condition
    {
      itt = 9; //Updating the itterator index to max, getting out of the loop
      counter--; //Updating number of fractions
    }
  }
  return counter; //Sending back the amount of fractions
}
/*Function name: summarize
Input: Array of fractions and number of fractions
Output: None
Algorithm: Sum fractions and printing result*/
void summarize(num fracs[], int counter)
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
