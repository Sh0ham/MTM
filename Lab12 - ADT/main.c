#include "ex.h"

void freeChr(void* ch);
void prntChr(void* ch);
BOOL cmpChr(char* ch_1, char* ch_2);

int main()
{
	char ch, *temp;
	int num, itt = 0;
	BOOL res;
	PNode head = NULL, tail = NULL;
	printf("Enter number of characters: ");
	scanf("%d", &num);
	printf("Enter %d characters, separated by space: ", num);
	for (; itt < num; itt++)
	{
		temp = (char*)malloc(sizeof(char));
		if (temp == NULL)
		{
			printf("\nCan't allocate data memory");
			freeAll(&head, freeChr);
			return 1;
		}
		scanf(" %c", temp);
		res = insertEntry(&head, &tail, temp, cmpChr);
		if (res == FALSE)
		{
			printf("\nCan't allocate node memory or data is allready exists");
			freeAll(&head, freeChr);
			return 1;
		}
	}
	printf("Your list is: ");
	printAll(head, prntChr);
	printf("\nEnter an element for deleting: ");
	scanf(" %c", &ch);
	res = deleteNode(&head, &tail, &ch, cmpChr, freeChr);
	FALSE == res ? printf("%c don't exists in list\n", ch) : 0;
	printf("Your current list is: ");
	printAll(head, prntChr);
	freeAll(&head, freeChr);
	printf("\nYour list was destroyed");
	return 0;
}

void freeChr(void* ch)
{
	free((char*)ch);
}

BOOL cmpChr(char* ch_1, char* ch_2)
{
	return ((*(char*)ch_1) == (*(char*)ch_2)) ? TRUE : FALSE;
}

void prntChr(void* ch)
{
	printf("%c ", *(char*)ch);
}
