#include "array.h"

int main()
{
	Stack st; //Program variables
	int del_value, flag;
	initStack(&st, 4);
	push(&st, 3);
	push(&st, 5);
	push(&st, 1);
	push(&st, 10);
	(flag = pop(&st, &del_value)) ? printf("\n%d was deleted", del_value) : 0;
	push(&st, 8);
	(flag = pop(&st, &del_value)) ? printf("\n%d was deleted", del_value) : 0;
	(flag = pop(&st, &del_value)) ? printf("\n%d was deleted", del_value) : 0;
	push(&st, 7);
	push(&st, 4);
	push(&st, 100);
	(flag = pop(&st, &del_value)) ? printf("\n%d was deleted", del_value) : 0;
	while (st.count)
	{
		(flag = pop(&st, &del_value)) ? printf("\n%d was deleted", del_value) : 0;
	}
	printf("\n");
	(flag = pop(&st, &del_value)) ? printf("\n%d was deleted", del_value) : 0;
	free(st.Array);
	return 0;
}
