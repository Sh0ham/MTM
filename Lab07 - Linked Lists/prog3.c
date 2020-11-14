#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Item //Structure declaration
{
	int num;
	float price;
	struct Item* next;
}*PItem;

void errMsg(char* msg); //Functions declaration
void AddNewItem(PItem*, PItem*, int, int, float);
void CreateList(PItem*, PItem*, FILE*);
void PrintItem(PItem);
void PrintList(PItem, char*);
void WriteListToFile(PItem, FILE*);
void DeleteList(PItem*);

int main()
{
  int a, n;
  float b;
  PItem head = NULL, tail = NULL;
  FILE* in;
  ((in = fopen("input_price.txt", "rt")) == NULL) ? errMsg("Couldn't find input.txt, ending program") : 0;
  CreateList(&head, &tail, in);
  PrintList(head, "\nThe Old List:\n");
  printf("\n\nEnter a number and the price\n");
  scanf("%d %f", &a, &b);
  printf("\nEnter a place for the new item:");
  scanf("%d", &n);
  AddNewItem(&head, &tail, n, a, b);
  PrintList(head, "\nThe New List:\n");
  fclose(in);
  ((in = fopen("input_price.txt", "wt")) == NULL) ? errMsg("Couldn't find input.txt, ending program") : 0;
  WriteListToFile(head, in);
  fclose(in);
  DeleteList(&head);
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

/*Function name: AddNewItem
Input: Pointer to head to list, tail of the list, two integers and float numbers
Output: None
Algorithm: Create new item and then linking it to the correct position*/
void AddNewItem(PItem* head, PItem* tail, int n, int a, float b)
{
  int itt = 0; //Functions variables
  PItem newItem, temp;
  temp = *head;
  newItem = (PItem)malloc(sizeof(struct Item));
  newItem == NULL ? (DeleteList(head), errMsg("Memory allocation failed, terminate program!")) : 0;
  newItem->num = a;
  newItem->price = b;
  if (n == 1)
  {
    newItem->next = *head;
    *head = newItem;
  }
  else
  {
    for (; itt < n-2; itt++)
    {
      temp == NULL ? errMsg("Memory allocation failed, terminate program!") : 0;
      temp = temp->next;
    }
    newItem->next = temp->next;
    temp->next = newItem;
  }
}

/*Function name: CreateList
Input: Pointer to head to list, tail of the list and a file
Output: None
Algorithm: Running with while loop, retrieve data from given file*/
void CreateList(PItem* head, PItem* tail, FILE* f)
{
  int a; //Function variables
  float b;
  PItem temp;
  while (fscanf(f, "%d %f", &a, &b) == 2)
  {
    temp = (PItem)malloc(sizeof(struct Item));
    temp == NULL ? (DeleteList(head), errMsg("Memory allocation failed, terminate program!")) : 0;
    temp->num = a;
    temp->price = b;
    temp->next = NULL;
    *head == NULL ? (*head = temp) : ((*tail)->next = temp);
    *tail = temp;
  }
}

/*Function name: PrintItem
Input: Node
Output: None
Algorithm: Printing a specific node*/
void PrintItem(PItem node)
{
  printf("%d,%.1f--> ", node->num, node->price);
}

/*Function name: PrintList
Input: List's head node and a string
Output: None
Algorithm: Running with while loop on the list, printing each node*/
void PrintList(PItem head, char* title)
{
  printf("%s", title);
  while (head)
  {
    PrintItem(head);
    head = head->next;
  }
}

/*Function name: WriteListToFile
Input: List's head node and a file
Output: None
Algorithm: Running with while loop, printing each node to the file*/
void WriteListToFile(PItem head, FILE* in)
{
  PItem temp = head;
  while (temp != NULL)
  {
    fprintf(in, "%d %.2f ", temp->num, temp->price);
    temp = temp->next;
  }
}

/*Function name: DeleteList
Input: Pointer to list's head
Output: None
Algorithm: Running with while loop, release memory allocated by the program*/
void DeleteList(PItem* head)
{
  PItem tmp = *head;
  while (*head)
  {
    tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }
}
