#define _CRT_SECURE_NO_WARNINGS
#define MAX 257
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node //Structure declaration
{
	char code[11];
	char *name;
	char Dep[4];
	int marks[3];
	float avg;
	struct node* next;
}std;

void Error_Msg(char* str); //Functions declaration
std* FromFileToList(std* head,FILE *in);
std* Delete_Stud(std* toDel,std* head);
void DeleteList(std* head);
void PrintList(std* head);
std* FindMax(std* head);

int main()
{
	int itt = 0;
	FILE *f;
	std *Head = NULL, *temp;
	((f = fopen("List.txt","rt")) == NULL) ? Error_Msg("Input error") : 0;
	Head = FromFileToList(Head, f);
	fclose(f);
	printf("\nThe list is:");
	PrintList(Head);
	temp = FindMax(Head);
  printf("\n\nThe student with max average:\n");
	printf("%s %s %s ", temp->code, temp->name, temp->Dep);
	for(; itt < 3; itt++)
	{
		printf(" %d ",temp->marks[itt]);
	}
	printf("\n\nThe list after change:");
	Head = Delete_Stud(FindMax(Head), Head);
	PrintList(Head);
	DeleteList(Head);
	return 0;
}

/*Function name: Error_Msg
Input: String
Output: None
Algorithm: Printing error message and exit*/
void Error_Msg(char* str)
{
	printf("\n%s", str);
	exit(1);
}

/*Function name: FromFileToList
Input: Pointer to head of the linked list and text file
Output: Pointer to head of the linked list
Algorithm: Read every line of the file, allocate memory for every student nodes
						Saving student's info into new node and point this node to head of
						linked list*/
std* FromFileToList(std* head, FILE *in)
{
	std* s; //Function variables
	char tempName[MAX];
	s = (std*)malloc(sizeof(std));
	if (s == NULL) //If couldn't allocated memory
	{
		while (head != NULL) //Release memory allocated by the program
		{
			s = head;
			head = head->next;
			free(s->name);
			free(s);
		}
		Error_Msg("Low memory");
	}
	while (fscanf(in, "%s%s%s%d%d%d", s->code, tempName, s->Dep, &s->marks[0], &s->marks[1], &s->marks[2]) != EOF)
	{
		s->name = (char*)malloc(sizeof(char)*(strlen(tempName)+1)); //Allocating memory for each student's name
		if (s->name == NULL) //If couldn't allocated memory
		{
			while (head != NULL) //Release memory allocated by the program
			{
				s = head;
				head = head->next;
				free(s->name);
				free(s);
			}
			Error_Msg("Low memory");
		}
		strcpy(s->name, tempName);
		s->avg = (s->marks[0] + s->marks[1] + s->marks[2]) / 3.0; //Calculate average score
		s->next = head; //Link s to the list
		head = s;
		s = (std*)malloc(sizeof(std)); //Allocate memory for new node in the linked list
		if (s == NULL) //If couldn't allocated memory
		{
			while(head != NULL) //Release memory allocated by the program
			{
				s = head;
				head = head->next;
				free(s->name);
				free(s);
			}
			Error_Msg("Low memory");
		}
	}
	free(s);
	return head;
}

/*Function name: Delete_Stud
Input: Two pointers
Output: Pointer to head of the linked list
Algorithm: Running on the list till found the student to remove*/
std* Delete_Stud(std* toDel, std* head)
{
	std *temp, *prev; //Function variables
	if (head == NULL)
	{
		return NULL;
	}
	if (toDel == head) //If the head need to be deleted
	{
		head = head->next; //Next node is the head
		free(toDel->name); //Release allocated memory
		free(toDel);
	}
	else
	{
		prev = head;
		temp = prev->next;
		while (temp != NULL)
		{
			if (toDel == temp)
			{
				prev->next = temp->next;
				free(toDel->name); //Release allocated memory
				free(toDel);
				return head; //Deleted node successfully exit the function
			}
			prev = prev->next; //Moving forward on the list
			temp = temp->next;
		}
	}
	return head;
}

/*Function name: DeleteList
Input: Pointer to head of the linked list
Output: None
Algorithm: Running with while loop, releasing memory allocated*/
void DeleteList(std* head)
{
	std* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->name);
		free(temp);
	}
}

/*Function name: PrintList
Input: Pointer to head of the linked list
Output: None
Algorithm: Running with while loop, printing each student*/
void PrintList(std* head)
{
	std* temp = head; //Function variable
	while (temp != NULL)
	{
		printf("\n%s %s %s %d %d %d", temp->code, temp->name, temp->Dep, temp->marks[0], temp->marks[1], temp->marks[2]);
		temp = temp->next;
	}
}

/*Function name: FindMax
Input: Pointer to head of the linked list
Output: Pointer to the
Algorithm: Running with while loop, finding the top student*/
std* FindMax(std* head)
{
	std *temp = head, *maxS = head; //Function variables
	while (temp != NULL)
	{
		temp->avg > maxS->avg ? maxS = temp : 0; //Logic test to find max
		temp = temp->next; //Moving forward on the list
	}
	return maxS; //Return max
}
