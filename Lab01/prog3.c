#define _CRT_SECURE_NO_WARNINGS
#define NUMELEMS 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findMin(char** arrP,int arrSize); //Function declaration

int main()
{
	char *a[] = {"Alona", "Nir", "Amina", "Yosef", "alice", "Amos", "bob"}; //Program variables
	int itt;
	for(itt = 0; itt < NUMELEMS; itt++) //For loop printing the strings
	{
		printf("%s\n", a[itt]);
	}
	printf("\n%s", findMin(a, NUMELEMS)); //Printing the minimum string
	return 0;
}

/*Function name: findMin
Input: Strings array and inetger
Output: Pointer to the first charcter of the minimum string
Algorithm: Comparing by strcmp function each string, updating the minimum if needed*/
char* findMin(char** arrP,int arrSize)
{
	int itt, min = 0; //Function variables
	for (itt = 1; itt < arrSize; itt++) //Running on each string
	{
		strcmp(arrP[itt], arrP[min]) < 0 ? min = itt : 0; //Comparing function
	}
	return arrP[min];
}
