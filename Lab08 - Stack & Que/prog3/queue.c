#include "queue.h"

/*Function name: enQueue
Input: Queue structure and integer
Output: None
Algorithm: Allocate memory for the new item insert it into the queue if there's available slot*/
void enQueue(PQue Q, int new_elem)
{
	Item *temp = (Item*)malloc(sizeof(Item));
	if (temp == NULL)
	{
		printf("Memory allocation failed.");
		free(temp);
		while (Q->size > 0)
		{
			temp = Q->head;
			Q->head = temp->next;
			free(temp);
		}
		exit(1);
	}
	if (Q->size == NUM)
	{
		printf("Queue is full! Can't enqueue this item.\n");
		free(temp);
		return;
	}
	temp->num = new_elem;
	temp->next = NULL;
	if (Q->size == 0)
	{
		Q->head = temp;
		Q->tail = temp;
	}
	else
	{
		temp->next = Q->head;
		Q->head = temp;
	}
	Q->size++;
}

/*Function name: deQueue
Input: Queue structure and ipointer to integer
Output: Zero if queue ended and one if not
Algorithm: Checking queue size, updating queue parameters as needed*/
int deQueue(PQue Q, int* del_value)
{
	Item *temp = Q->tail;
	if (Q->size == 0)
	{
		printf("Queue is empty! Nothing to dequeue.\n");
		return 0;
	}
	*del_value = temp->num;
	temp = Q->head;
	if (Q->size == 1)
	{
		free(temp);
		Q->head = NULL;
		Q->tail = NULL;
		Q->size--;
		return 1;
	}
	while (temp->next != Q->tail)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
	Q->tail = temp;
	Q->size--;
	return 1;
}
