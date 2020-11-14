#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item //Structure declaration
{
	int code;
	char name[11];
	struct Item* next;
}Item;

int main()
{
	int itt = 1;
	Item *Head = NULL, *temp;
	for(; itt <= N; itt++)
	{
		temp = (Item*)malloc(sizeof(Item)); //Allocating memory for new node
		if (temp == NULL) //If memory allocation failed, free all nodes and exit
		{
			printf("Low memory");
			while (Head != NULL)
			{
				temp = Head;
				Head = Head->next;
				free(temp);
			}
			exit(1);
		}
		printf("Enter a new code and name: ");
		scanf("%d %s", &temp->code, temp->name);
		temp->next = Head; //Moving head node to be the second node of the list
		Head = temp; //Make the new node the head of the list
	}
	temp = Head;
	printf("\n\nThe List is: "); //Printing nodes
	while(temp != NULL)
	{
		printf("%d %s --> ", temp->code, temp->name);
		temp = temp->next;
	}
	while(Head != NULL) //Free all the node's memory allocated by the program
	{
		temp = Head;
		Head = Head->next;
		free(temp);
	}
	return 0;
}
