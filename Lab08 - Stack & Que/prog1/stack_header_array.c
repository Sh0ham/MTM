#include "stack_header_array.h"

/*Function name: push
Input: Stack and integer
Output: None
Algorithm: Checking if spot is available in the stack, if so - adding it, else printing error*/
void push(PStack s, int new_elem)
{
	Item* temp;
	if (s->size < NUM)
	{
		temp = (Item*)malloc(sizeof(Item));
		(temp == NULL) ? deleteList(s->head), errMsg("Memory alloction error.\n") : 0;
		temp->num = new_elem;
		(s->head == NULL) ? (s->head = temp, temp->next = NULL) : (temp->next = s->head, s->head = temp);
		printf("The number %d was added to stack.\n", new_elem);
		s->size++;
	}
	else
	{
		printf("The stack is full.\n");
		return;
	}
}

/*Function name: initial
Input: Stack
Output: None
Algorithm: Initialize the stack*/
void initial(PStack st)
{
	st->head = NULL;
	st->size = 0;
}

/*Function name: pop
Input: Stack and pointer pointer to integer
Output: Return zero if the stack is empty and one if not
Algorithm: Checking stack size, if it's not zero release head*/
int pop(PStack s, int* del_value)
{
	Item* temp;
	if (s->size == 0)
	{
		printf("The stack is empty.\n");
		return 0;
	}
	else
	{
			temp = s->head;
			*del_value = temp->num;
			s->head = temp-> next;
			temp->next = NULL;
			free(temp);
			s->size--;
	}
	return 1;
}

/*Function name: deleteList
Input: Stack
Output: None
Algorithm: Running with while loop. Release head as long as possible*/
void deleteList(PStack s)
{
	PStack temp;
	while (s->head != NULL)
	{
		temp = s->head;
		s->head = s->head->next;
		free(temp);
	}
}

/*Function name: errMsg
Input: None
Output: None
Algorithm: Printing error message and terminate program*/
void errMsg(char msg)
{
	printf("\n%s", msg);
	exit(1);
}
