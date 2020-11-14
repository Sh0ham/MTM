#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Item //Structures declaration
{
  int num;
	struct Item* next;
}Item;

typedef struct List
{
	Item* head;
	Item* tail;
	int count;
}List;

void errMsg(char* msg); //Functions declaration
void AddAsFirst(Item*, List*);
void AddAsLast(Item*, List*);
void MoveToAnotherList(List*, List*, List*);
void CreateList(List*, FILE *);
void PrintItem(Item*);
void PrintList(List*, char*);
void DeleteList(List*);

int main()
{
  List L, Posit, Negat; //Program variables
  FILE* in;
  ((in = fopen("ThreeLists.txt", "rt")) == NULL) ? errMsg("Couldn't find input.txt, ending program") : 0;
  L.head = NULL, L.tail = NULL, L.count = 0;
  Posit.head = NULL, Posit.tail = NULL, Posit.count = 0;
  Negat.head = NULL, Negat.tail = NULL, Negat.count = 0;
  CreateList(&L, in);
  PrintList(&L, "\nMy List:\n");
  MoveToAnotherList(&L, &Posit, &Negat);
  PrintList(&Posit, "\n\nThe Positive List:\n");
  PrintList(&Negat, "\n\nThe Negative List:\n");
  fclose(in);
  DeleteList(&Posit);
  DeleteList(&Negat);
  return 0;
}

/*Function name: errMsg
Input: String
Output: None
Algorithm: Printing error message and terminate program*/
void errMsg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}

/*Function name: AddAsFirst
Input: Item and list
Output: None
Algorithm: Adding node to head to the list*/
void AddAsFirst(Item* temp, List* N)
{
  if (N->head == NULL)
  {
    N->head = temp;
		N->tail = N->head;
		temp->next = NULL;
  }
	else
  {
    temp->next = N->head;
		N->head = temp;
  }
	N->count++;
}

/*Function name: AddAsLast
Input: Node and list
Output: None
Algorithm: Adding node to tail of the list*/
void AddAsLast(Item* temp, List* P)
{
  if (P->head == NULL)
  {
    P->head = temp;
		P->tail = temp;
		temp->next = NULL;
  }
	else
  {
    P->tail->next = temp;
		P->tail = temp;
		temp->next = NULL;
  }
	P->count++;
}

/*Function name: MoveToAnotherList
Input: Three lists
Output: None
Algorithm: Check if there are nodes in the list, if there are adds to tail and if not to head*/
void MoveToAnotherList(List* L, List* P, List* N)
{
  Item* temp; //Function variable
  while (L->head != NULL)
  {
    temp = L->head;
    L->head = L->head->next;
    temp->next = NULL;
    temp->num >= 0 ? AddAsLast(temp, P) : AddAsFirst(temp, N);
  }
  L->tail = NULL;
  L->count = 0;
}

/*Function name: CreateList
Input: List and file
Output: None
Algorithm: Running with while loop on file, scanning integers and adds them to the list*/
void CreateList(List* L, FILE* f)
{
  int value; //Function variables
  Item* temp;
  while (fscanf(f, "%d", &value) == 1)
  {
    temp = (Item*)malloc(sizeof(struct Item));
    temp == NULL ? (DeleteList(L), errMsg("Memory allocation failed, terminate program!")) : 0;
    temp->num = value;
    temp->next = NULL;
    L->head == NULL ? (L->head = temp) : (L->tail->next = temp);
    L->tail = temp;
    L->count++;
  }
}

/*Function name: PrintItem
Input: Node
Output: None
Algorithm: Printing specific node*/
void PrintItem(Item* node)
{
  printf("%d--> ", node->num);
}

/*Function name: PrintList
Input: List and string
Output: None
Algorithm: Printing title and than with while loop, printing each node*/
void PrintList(List* L, char* title)
{
  Item* temp = L->head; //Function variable
  printf("%s", title);
  while (temp)
  {
    PrintItem(temp);
    temp = temp->next;
  }
  printf("\nThere are %d items in the list", L->count);
}

/*Function name: DeleteList
Input: List
Output: None
Algorithm: Running with while loop, release all memory allocated by the program*/
void DeleteList(List* L)
{
  Item* temp; //Function variable
	while (L->head != NULL)
	{
		temp = L->head;
		L->head = L->head->next;
		free(temp);
	}
}
