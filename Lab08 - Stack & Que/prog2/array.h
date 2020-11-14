#ifndef _array
#define _array
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Stack //Structure declaration
{
	int top;
	int* Array;
	int size;
	int count;
}Stack, *PStack;

void initStack(PStack s, int size); //Function declaration
void push(PStack s, int new_elem);
int pop(PStack s, int* del_value);
void errMsg(char* msg);

#endif
