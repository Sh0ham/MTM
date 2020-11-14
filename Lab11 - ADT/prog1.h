#ifndef _prog1f
#define _prog1f

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node STACKNODE, *PSTACKNODE;

void* top(STACKNODE* stack);
void push(void* key, STACKNODE** stack);
void pop(PSTACKNODE* stack, void(*free_data)(void*));
int isEmpty(STACKNODE* stack);

#endif
