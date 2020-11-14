#ifndef _queue
#define _queue
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 10

typedef struct Item //Structure decleration
{
	int num;
	struct Item* next;
}Item;
typedef struct Que
{
	Item *head, *tail;
	int size;
}Queue, *PQue;

void enQueue(PQue Q, int new_elem); //Function decleration
int deQueue(PQue Q, int *del_value);

#endif
