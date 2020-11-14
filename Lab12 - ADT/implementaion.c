#include "ex.h"

typedef struct  ListNode
{
	void* data;
	struct  ListNode* next;
}ListNode;

BOOL insertEntry(PNode* head, PNode* tail, void* data, compare_func func)
{
	ListNode* temp, * new_node;
	if (*head == NULL)
	{
		temp = (ListNode*)malloc(sizeof(ListNode));
		if (temp == NULL)
		{
			printf("Memory alloction error");
			return FALSE;
		}
		temp->next = NULL;
		temp->data = data;
		(*head) = temp;
		temp->next = NULL;
		(*tail) = temp;
	}
	else
	{
		temp = (*head);
		while (temp != NULL)
		{
			if (func(temp->data, data))
			{
				return FALSE;
			}
			temp = temp->next;
		}
		if (temp == NULL)
		{
			new_node = (ListNode*)malloc(sizeof(ListNode));
			if (new_node == NULL)
			{
				printf("Memory alloction error");
				return FALSE;
			}
			new_node->data = data;
			temp = (*tail);
			(*tail) = new_node;
			temp->next = new_node;
			new_node->next = NULL;

		}
		else return FALSE;
	}
	return TRUE;
}

BOOL deleteNode(PNode* head, PNode* tail, void* todel, compare_func func1, free_func func2)
{
	PNode temp2delete= *head, temp=*head;

	while (temp != NULL)
	{
		if (func1(temp->data, todel))
		{
			if (temp == (*head))
			{
				*head = (*head)->next;
				temp->next = NULL;
				func2(temp->data);
				free(temp);
				return TRUE;
			}
			else
			{
				if (temp->next == NULL)
				{
					(*tail) = temp2delete;
					temp2delete->next = NULL;
				}
				else
				{
					temp2delete->next = temp->next;
					temp2delete = temp;
					temp2delete->next = NULL;

				}
				func2(temp->data);
				free(temp);
				return TRUE;
			}
		}
		temp2delete = temp;
		temp = temp->next;
	}
	return FALSE;
}

void printAll(PNode head, print_func func)
{
	PNode temp = head;
	while (temp != NULL)
	{
		func(temp->data);
		temp = temp->next;
	}
}

void freeAll(PNode* head, free_func func)
{
	PNode temp;
	while (*head)
	{
		temp = (*head);
		(*head) = temp->next;
		free(temp->data);
		free(temp);
	}
}
