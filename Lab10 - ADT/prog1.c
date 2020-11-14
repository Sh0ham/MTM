#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

float func1(int x); //Functions declaration
float func2(int x);
double sumSquare(int m, int n, float(*f)(int a));

int main()
{
	printf("The sum of func2: %.5lf\nThe sum of func1: %.5lf", sumSquare(2, 13, func2), sumSquare(1, 10000, func1));
	return 0;
}

/*Function name: sumSquare
Input: Two integers and function's pointer
Output: Floating point number
Algorithm: Sum all the powers of numbers from m to n after other function calculation by sending from the general function to specific function for calculation.*/
double sumSquare(int m, int n, float(*f)(int a))
{
	double sum = 0;
	int itt;
	for (itt = m; itt <= n; itt++)
	{
		sum += pow(f(itt), 2.0);
	}
	return sum;
}
float func1(int x)
{
	return 1.0/x;
}
float func2(int x)
{
	return x/5.0;
}
