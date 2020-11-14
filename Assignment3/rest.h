#define _CRT_SECURE_NO_WARNINGS
#ifndef _rest
#define _rest
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Kitchen //Structures declaration
{
	char* prdctName;
	int Price;
	int quantity;
	int Maxquantity;
	struct Kitchen* next;
}Kitchen, *PKtchn;

typedef struct Order
{
	char* prdctName;
	int quantity;
	int Price;
	struct Order* next;
	struct Order* prev;

}Order, *POrdr;

typedef struct Table
{
	int tblNum;
	int bill;
	POrdr orders;

}Table, *PTabl;

void errMsg(FILE* out, char* msg); //Functions declaration
void crtPrdcts(FILE* out, FILE* in, PKtchn* p);
void addItms(FILE* out, char* prod, int q, PKtchn* ptr);
void rmvTbl(FILE* out, int tblNum, int MaxTablesNum, PTabl array, PKtchn* k);
void rmvItm(FILE* out, int tblNum, char* prdctName, int quantity, int MaxTablesNum, PTabl array);
void ordrItm(FILE* out, int tblNum, char* prdctName, int quantity, int MaxTablesNum, PTabl array, PKtchn* p);

#endif
