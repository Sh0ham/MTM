#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <stdio.h>
#include <stdlib.h>

typedef struct Item //Structure declaration
{
	int num;
	struct Item* next;
}*PItem;

void errMsg(char* msg); //Functions declaration
void CreateListFromArray(PItem*, PItem*, int*);
void DeleteList(PItem*);
void ListDisplay(PItem);
int ListLength(PItem);

int main()
{
	int Arr[N] = {3,4,1,0,8};
	PItem list = NULL, tail = NULL;

	CreateListFromArray(&list, &tail, Arr);
	printf("The length of the list is %d members\n", ListLength(list));
	printf("\nThe list is:\n");
	ListDisplay(list);
	DeleteList(&list);
	tail = NULL;
	return 0;
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

/*Function name: CreateListFromArray
Input: Head node, tail node and array
Output: None
Algorithm: Running with for loop on the array, allocate memory and copying array's integers*/
void CreateListFromArray(PItem* head, PItem* tail, int* Arr)
{
  int itt = 0; //Function variables
	PItem temp;
	for (; itt < N; itt++)
	{
		temp = (PItem)malloc(sizeof(struct Item));
		temp == NULL ? (DeleteList(head), errMsg("Memmory!")) : 0;
		temp->num = Arr[itt];
		temp->next = NULL;
		*head == NULL ? *head = temp : ((*tail)->next = temp);
		*tail = temp;
	}
}

/*Function name: DeleteList
Input: Pointer to head node
Output: None
Algorithm: Running with while loop, release memory allocated by program*/
void DeleteList(PItem* head)
{
  PItem tmp = *head; //Function variable
  while (*head)
  {
    tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }
}

/*Function name: ListDisplay
Input: List
Output: None
Algorithm: Recursively printing each node from the list*/
void ListDisplay(PItem list)
{
  return (list != NULL) ? (printf("%d ", list->num), ListDisplay(list->next)) : NULL;
}

/*Function name: ListLength
Input: List
Output: Number of nodes in the list
Algorithm: Recursively counting nodes from the list*/
int ListLength(PItem list)
{
  return (list != NULL) ? (1+ListLength(list->next)) : 0;
}
