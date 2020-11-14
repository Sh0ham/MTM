#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bitCount(unsigned int num); //Function declaration
void binPrint(unsigned int num);

int main()
{
  unsigned int num; //Program Variable
  printf("Enter a number: ");
  scanf("%d", &num);
  printf("There are %d bits equal to one in %d\n", bitCount(num), num);
  printf("The binary representation of %d is: ", num);
  binPrint(num);
  return 0;
}

/*Function name: bitCount
Input: Integer
Output: Integer
Algorithm: Running with a while loop, counting how many 1 bits are in a given number*/
int bitCount(unsigned int num)
{
  unsigned int counter = 0;
	while (num)
	{
		counter += num&1;
		num >>= 1;
	}
	return counter;
}

/*Function name: binPrint
Input: Integer
Output: None
Algorithm: Running with a while loop, printing each bit*/
void binPrint(unsigned int num)
{
  unsigned int mask = 1;
	mask <<= ((sizeof(unsigned int)*8)-1);
	while (mask)
	{
		num&mask ? printf("1") : printf("0");
		mask >>= 1;
	}
}
