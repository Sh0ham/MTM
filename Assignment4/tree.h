#define _CRT_SECURE_NO_WARNINGS
#ifndef _tree
#define _tree
#include <stdio.h>
#include <stdlib.h>

typedef enum //Structures declaration
{
  equal = 0,
  bigger = 1,
  smaller = 2
}option;

typedef struct tree *Ptree;
typedef void(*PRINT_ELEMENT)(void*, FILE* out);
typedef option(*Cmp_func)(void* elemnt1, void* elemnt2);

Ptree createTree(void* key); //Functions declaration
void addTree(FILE* out, Ptree* tree, Ptree* STree, void* newKey, int count, option (*cmpInt)(void* elemnt1, void* elemnt2), void(*freeKey)(void* key));
void emptyTree(Ptree root, void(*freeKey)(void* key));
void printInOrder(Ptree root, void(*PRINT_ELEMENT)(FILE*, void*), FILE* out);
void max(Ptree tree, void(*PRINT_ELEMENT)(FILE*, void*), FILE* out);
int printSmallest(Ptree tree, void(*PRINT_ELEMENT)(FILE*, void*), int k, FILE* out);
int treeHeight(Ptree tree);

#endif
