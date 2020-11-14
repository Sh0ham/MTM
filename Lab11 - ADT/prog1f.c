#include "prog1.h"

typedef struct node
{
	void* data;
	struct node* next;
}STACKNODE, *PSTACKNODE;

void* top(STACKNODE* stack)
{
	return stack->data;
}

void push(void* key, STACKNODE** stack)
{
	STACKNODE* newnode;
	newnode = (STACKNODE*)malloc(sizeof(STACKNODE));
	newnode->data = key;
	newnode->next = (*stack);
	(*stack) = newnode;
}

void pop(PSTACKNODE* stack, void(*free_data)(void*))
{
	STACKNODE* oldnode;
	oldnode = (*stack);
	(*stack) = (*stack)->next;
	free_data(oldnode->data);
	free(oldnode);
}

int isEmpty(STACKNODE* stack)
{
	return (stack == NULL);
}
