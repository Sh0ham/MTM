#include "prog1.h"

void free_char(void* elem);

int main()
{
	STACKNODE* stack = NULL;
	char key;
	char* temp_key;
	puts("Enter characters, separated by space. Press enter to stop:");
	while ((key = getchar()) != '\n' && key != EOF)
	{
		temp_key = (char*)malloc(sizeof(char));
		*temp_key = key;
		push(temp_key, &stack);
	}
	puts("Here are the characters in reverse order:");
	while (!isEmpty(stack))
	{
		printf("%c", *(char*)top(stack));
		pop(&stack, free_char);
	}
	return 0;
}

void free_char(void* elem)
{
	free(elem);
}
