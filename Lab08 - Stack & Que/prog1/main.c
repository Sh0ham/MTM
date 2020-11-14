#include "stack_header_array.h"

int main()
{
	Stack st; //Program variables
	int arr[NUM] = {1,2,3,4,5}, itt, del_value;
	initial(&st);
	for (itt = 0; itt < NUM+1; itt++)
	{
		push(&st, arr[itt]);
	}
	for (itt = 0; itt < NUM+1; itt++)
	{
		(pop(&st, &del_value) == 1) ? printf("The deleted value is: %d.\n", del_value) : 0;
	}
	return 0;
}
