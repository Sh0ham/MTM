#ifndef _implementaion
#define _implementaion
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FALSE,
	TRUE
}BOOL;

typedef BOOL(*compare_func)(char*, char*);
typedef void (*print_func)(void*);
typedef void (*free_func)(void*);

typedef  struct ListNode* PNode;
BOOL insertEntry(PNode* head, PNode* tail, void* data, compare_func func);
BOOL deleteNode(PNode* head, PNode* tail, void* todel, compare_func func1, free_func func2);
void printAll(PNode head, print_func func);
void freeAll(PNode* head, free_func func);

#endif
#pragma once
