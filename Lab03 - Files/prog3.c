#define _CRT_SECURE_NO_WARNINGS
#define N 4
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Complex //Structures declaration
{
  float x;
  float yi;
}Complex;

float CRadius(Complex); //Function declaration
void InputAndWriteToFile(FILE *f);
int CheckFile(FILE *f, float m);
void Error_Msg(char* str);

int main()
{
	FILE *f; //Program Variables
	int counter;
	float m; //Minimum radius to count from
  printf("Let M be the radius of complex numbers to count from, enter your M: "); //Asking user for radius
  scanf("%f", &m); //Retrieving data from user
  (f = fopen("complex_number.txt", "wt")) ? 0 : Error_Msg("File didn't open successfully"); //Opening file and exit if failed
	InputAndWriteToFile(f); //Writing numbers to the file
	fclose(f); //Closing file
  (f = fopen("complex_number.txt", "rt")) ? 0 : Error_Msg("File didn't open successfully"); //Opening file and exit if failed
	counter = CheckFile(f, m) > 1 ? printf("There are %d big numbers", counter) : printf("There is 1 big number"); //Printing result
	fclose(f); //Closing file
  return 0;
}

/*Function name: CRadius
Input: Complex number structure
Output: Number's radius
Algorithm: Square root of it's sum of powers*/
float CRadius(Complex Complex)
{
  return sqrt(pow(Complex.x,2) + pow(Complex.yi,2)); //Return result
}

/*Function name: InputAndWriteToFile
Input: Text file
Output: None
Algorithm: Running with for loop, getting user's numbers and writing them to text file*/
void InputAndWriteToFile(FILE *f)
{
	Complex z[N]; //Function variables
	int itt = 0;
	float radius;
	printf("Enter %d complex numbers:\n", N); //Asking user for data
	for (; itt < N; itt++)
	{
		scanf("%f %f", &z[itt].x, &z[itt].yi); //Retrieving data
		radius = CRadius(z[itt]); //Calculating number's radius
		fprintf(f, "%.1f %.1f %.1f\n", z[itt].x, z[itt].yi, radius); //Writing down values to file
	}
}

/*Function name: CheckFile
Input: Text file and real number
Output: Number of compelx numbers with larger radius than given
Algorithm: Running with for loop, updating counter on every radius that is bigger than we checked*/
int CheckFile(FILE *f, float m)
{
	int itt = 0, counter = 0; //Function variables
	float radius, tempXY;
	for (; itt < N; itt++)
	{
		fscanf(f, "%f" "%f" "%f", &tempXY, &tempXY, &radius); //Retrieving radius data
		radius > m ? counter++ : 0; //Checking if radius is big enough and updating the counter
	}
	return counter;
}

/*Function name: Error_Msg
Input: Pointer to the first letter of a charcters array
Output: None
Algorithm: Printing error and exit*/
void Error_Msg(char* str)
{
   printf("\n%s", str); //Printing error message
   exit(1);
}
