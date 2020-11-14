#define _CRT_SECURE_NO_WARNINGS
#define MAX 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book //Structures declaration
{
	char code[10];
	char* BookName;
}Book;
typedef struct Library
{
	char LibName[MAX];
	int amountBooks;
	Book* Book;
}Library;

void input_book(Book* B,FILE *in); //Function declaration
void input_library(Library *L,FILE *in);
void output_book(Book* B,FILE *out);
void output_library(Library* L,FILE *out);
void Get_Lost(char* str);

int main()
{
	FILE *in, *out; //Program Variables
	Library Libr;
	int itt;
	(in = fopen("input.txt", "rt")) ? 0 : Get_Lost("Cannot open file"); //Opening file and exit if failed
	input_library(&Libr, in); //Retrieving data
	fclose(in); //Closing file to reopen it in writing mode
	(out = fopen("output.txt", "wt")) ? 0 : Get_Lost("Cannot open file"); //Opening file and exit if failed
	output_library(&Libr, out); //Writing data
	fclose(out); //Closing file
  for(itt = 0; itt < Libr.amountBooks; itt++) //Releasing memory allocated by program
	{
		free(Libr.Book[itt].BookName);
	}
	free(Libr.Book);
  return 0;
}

/*Function name: input_book
Input: Books structure and text file
Output: None
Algorithm: Copying books using strcpy*/
void input_book(Book* B,FILE *in)
{
	char helper[MAX + 1]; //Function Variables
	fscanf(in, "%s %s", B->code, helper);
	B->BookName = (char*)malloc((strlen(helper)+1));
	B->BookName == NULL ? Get_Lost("Cannot open file"), free(B->BookName) : 0;
	strcpy(B->BookName, helper); //Copying name from temp holder
}

/*Function name: input_library
Input: Library structure and text file
Output: None
Algorithm: Running with for loop, retrieving each book name*/
void input_library(Library *L,FILE *in)
{
	int itt = 0; //Function Variables
	fscanf(in, "%s", L->LibName); //Set variables from file
	fscanf(in, "%d", &L->amountBooks);
	L->Book = (Book*)malloc((L->amountBooks)*sizeof(Book));
	L->Book == NULL ? Get_Lost("Cannot open file"), free(L->Book) : 0;
	for (; itt < L->amountBooks; itt++)
	{
		input_book(&L->Book[itt], in);
	}
}

/*Function name: output_book
Input: Books structure and text file
Output: None
Algorithm: Writing book to file, with it's values*/
void output_book(Book* B,FILE *out)
{
	fprintf(out, "%-12s %s\n", B->code, B->BookName);
}

/*Function name: output_library
Input: Library structure and text file
Output: None
Algorithm: Running with for loop, writing each book name*/
void output_library(Library* L,FILE *out)
{
	int itt = 0; //Function Variables
	fprintf(out, "%s\n", L->LibName);
	for (; itt < L->amountBooks; itt++)
	{
		output_book(&L->Book[itt], out);
	}
}

/*Function name: Get_Lost
Input: Pointer to the first letter of a charcters array
Output: None
Algorithm: Printing error and exit*/
void Get_Lost(char* str)
{
	printf("\n%s", str);
  exit(1);
}
