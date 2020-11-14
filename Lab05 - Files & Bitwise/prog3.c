#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void binPrint(unsigned char ch); //Function declaration
unsigned char checkMS(unsigned char ch);
unsigned char changeBit(unsigned char ch, int num);

int main()
{
  unsigned char numSt = 102, numNd = 58; //Program Variables
	int num = 0;
  char flag;
	printf("The first part:\nThe binary representation of the decimal number %d is: ", numSt);
	binPrint(numSt);
	numSt = checkMS(numSt);
	printf("\nThe binary representation of the new decimal number %d is: ", numSt);
	binPrint(numSt);
	printf("\n\nThe second part:\nThe binary representation of the decimal number %d is: ", numNd);
	binPrint(numNd);
	printf("\nEnter a number of the bit to change(1-8): ");
  while ((scanf("%d%c", &num, &flag) != 2 || flag != '\n') || num < 1 || num > 8) //Logic condition to check if bit chosen correctly
  {
    rewind(stdin); //Reset input, avoiding infinite loop
    printf("Your chosen bit must be an integer between 1 and 8!\nEnter a number of the bit to change(1-8): ");
  }
	numNd = changeBit(numNd, num);
	printf("\nThe binary representation of the new decimal number %d is: ", numNd);
	binPrint(numNd);
	return 0;
}

/*Function name: binPrint
Input: Charcter
Output: None
Algorithm: Printint the binary represntion of a char, moving bit by bit*/
void binPrint(unsigned char ch)
{
  unsigned int mask = 1; //Function Variable
  mask <<= ((sizeof(unsigned char)*8)-1);
  while (mask)
  {
    ch&mask ? printf("1") : printf("0");
    mask >>= 1;
  }
}

/*Function name: checkMS
Input: Charcter
Output: Charcter
Algorithm: OR Comapring MSB with mask of 1*/
unsigned char checkMS(unsigned char ch)
{
  unsigned int mask = 1; //Function Variable
  mask <<= ((sizeof(unsigned char)*8)-1);
  return ch|mask;
}

/*Function name: changeBit
Input: Charcter and integer
Output: Charcter
Algorithm: XOR Comapring the bit and mask of 1*/
unsigned char changeBit(unsigned char ch, int num)
{
  unsigned mask = 1; //Function Variable
  mask <<= ((sizeof(unsigned char)*8)-1);
  mask >>= sizeof(unsigned char)*(num-1);
  return ch^mask;
}
