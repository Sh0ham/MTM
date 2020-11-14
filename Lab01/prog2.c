#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void set_2d(float** a, int m, int n); //Function declaration
void print_2d(float** a, int m, int n);

int main( )
{
	int m, n, itt = 0; //Program variables
	float** a;
	printf("\nenter m and n, for m*n array: \n"); //Asking matrix dimension from user
	scanf("%d %d", &m, &n); //Getting matrix dimension from user
	assert(a = (float**)malloc(m*sizeof(float*))); //Initializing pointers array
	for (; itt < m; itt++) //Initializing coloums loop
	{
		assert(a[itt] = (float*)malloc(n*sizeof(float))); //Initializing values arrays
	}
	set_2d(a,m,n); //Setting matrix values
	print_2d(a,m,n); //Printing matrix values
	for (itt = 0; itt < m; itt++) //Release coloums loop
	{
		free(a[itt]);
	}
	free(a);
	return 0;
}

/*Function name: set_2d
Input: Pointer to first slot of two dimension matrix and two integers
Output: None
Algorithm: Running with two for loops, settting values to the matrix*/
void set_2d(float** a, int m, int n)
{
	int itt, jtt, k = 1; //Function variables
	for (itt = 0; itt < m; itt++) //Rows loop
	{
		for (jtt = 0; jtt < n; jtt++) //Coloums loop
		{
			a[itt][jtt] = k++;
		}
	}
}
/*Function name: print_2d
Input: Pointer to first slot of two dimension matrix and two integers
Output: None
Algorithm: Running with two for loops, printing values from the matrix*/
void print_2d(float** a, int m, int n)
{
	int itt, jtt; //Function variables
	for (itt = 0; itt < m; itt++) //Rows loop
	{
		for (jtt = 0; jtt < n; jtt++) //Coloums loop
		{
			printf("%7.1f", a[itt][jtt]);
		}
		printf("\n");
	}
}
