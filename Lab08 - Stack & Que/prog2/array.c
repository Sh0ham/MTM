#include "array.h"

/*Function name: initStack
Input:
Output:
Algorithm: */
void initStack(PStack s, int size)
{
	s->Array = (int*)malloc(sizeof(int) * size);
	s->Array == NULL ? errMsg("\nMemory alloction error.\n") : 0;
	s->size = size;
	s->count = 0;
	s->top = -1;
}

/*Function name: push
Input: Stack and integer
Output: None
Algorithm: Push into the the stack*/
void push(PStack s, int new_elem)
{
	if (s->count != s->size)
	{
		s->Array[s->count] = new_elem;
		s->top++;
		s->count++;
	}
	else
	{
		printf("\nThe Stack is full.\n");
	}
}

/*Function name: pop
Input: Stack and pointer to integer
Output: Return zero if stack is empty and one if not
Algorithm: Checking stack counter, if greater than zero, pop the last variable*/
int pop(PStack s, int* del_value)
{
	int temp;
	if (s->count == 0)
	{
		printf("The stack is empty\n");
		return 0;
	}
	else
	{
		*del_value = s->Array[s->top];
		s->top--;
		s->count--;
	}
	return 1;
}

/*Function name: errMsg
Input: None
Output: None
Algorithm: Printing error message and terminate program*/
void errMsg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}
