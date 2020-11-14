#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FALSE,
	TRUE
}BOOL;

BOOL intSum(void*, void*, void*); //Functions declaration
BOOL floatSum(void*, void*, void*);
BOOL Sum(BOOL(*f)(void*, void*, void*), void** p_num, void* number);

int main()
{
	int num[] = {3,5,23,5,6}, itt, value; //Program variables
	float fnum[] = {3.5,5.0,2.3,5.8,6.2}, fvalue;
	void* p_num[N];

	for (itt = 0; itt < N; itt++)
	{
		p_num[itt] = &num[itt];
	}
	printf("\nPlease enter an integer number: ");
	scanf("%d", &value);
	(Sum(intSum, p_num, &value) == TRUE) ? printf("There is such sum\n") : printf("There is no such sum\n");
	for (itt = 0; itt < N; itt++)
	{
		p_num[itt] = &fnum[itt];
	}
	printf("\nPlease enter a float number ");
	scanf("%f", &fvalue);
	(Sum(floatSum, p_num, &fvalue) == TRUE) ? printf("There is such sum\n") : printf("There is no such sum\n");
	return 0;
}

/*Function name: intSum
Input: 3 Pointers
Output: True or False
Algorithm: Checks if third pointer is equal to sum of first two pointers*/
BOOL intSum(void* a, void* b, void* c)
{
	return (*(int*)a + *(int*)b == *(int*)c) ? TRUE : FALSE;
}

/*Function name: floatSum
Input: 3 Pointers
Output: True or False
Algorithm: Checks if third pointer is equal to sum of first two pointers*/
BOOL floatSum(void* a, void* b, void* c)
{
	return ((*(float*)a + *(float*)b) == (*(float*)c)) ? TRUE : FALSE;
}

/*Function name: Sum
Input: Function pointer, double pointer and pointer
Output: True or False
Algorithm: Running with two for loops, checking every 2 slots from the array*/
BOOL Sum(BOOL(*f)(void*, void*, void*), void** p_num , void* number)
{
	int itt, jtt;
	for (itt = 0; itt < N-1; itt++) {
		for (jtt = itt+1; jtt < N; jtt++) {

			if (f(p_num[itt], p_num[jtt], number))
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}
