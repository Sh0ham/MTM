#ifndef _stack_header_array
#define _stack_header_array
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NUM 5

typedef struct Item //Structures declaration
{
	int num;
	struct Item* next;
}Item;

typedef struct Stack
{
	Item* head;
	int size;
}Stack, *PStack;

void push(PStack s, int new_elem); //Functions declaration
int pop(PStack s, int* del_value);
void initial(PStack st);
void deleteList(PStack s);
void errMsg(char msg);

#endif
