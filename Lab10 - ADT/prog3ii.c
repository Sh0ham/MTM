#define _CRT_SECURE_NO_WARNINGS
#define N 5
#define LENGTH 30
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
	FALSE,
	TRUE
}BOOL;

BOOL IsFull(); //Functions declaration
BOOL strComp(void *FirstElement, void *SecondElement);
void Insert(BOOL(*f)(void *, void *), void *Element, void ** Parray);

int CurrentCount = 0;

int main()
{
  char* Array[N]; //Program variables
  void* PArray[N];
  int itt;
  char TempStr[LENGTH];

  printf("Enter strings with space between them, 'end' to finish: ");
  scanf("%s", TempStr);

  while(strcmp(TempStr, "end"))
  {
    if(!IsFull())
    {
      Array[CurrentCount] = (char*)malloc(strlen(TempStr)+1);
      strcpy(Array[CurrentCount], TempStr);
      Insert(strComp, Array[CurrentCount], PArray);
      scanf("%s", TempStr);
    }
    else
    {
      printf("The array is full");
      break;
    }
 }
 printf("\nYour sorted array is: \n");
 for(itt = 0; itt < CurrentCount; itt++)
 {
   printf("%s ", (char*)PArray[itt]);
 }
 for(itt = 0; itt < CurrentCount; itt++)
 {
   free(Array[itt]);
 }
  return 0;
}

/*Function name: IsFull
Input: None
Output: True or False
Algorithm: Return true or false, depends on CurrentCount value*/
BOOL IsFull()
{
 return (CurrentCount == N) ? TRUE : FALSE;
}

/*Function name: strComp
Input: Two pointers
Output: True or False
Algorithm: Comparing 2 strings based on strcmp function*/
BOOL strComp(void *FirstElement, void *SecondElement)
{
  return (strcmp((char*)FirstElement, (char*)SecondElement) > 0) ? TRUE : FALSE;
}

/*Function name: Insert
Input: Pointer to function, one double pointer and one regular pointer
Output: None
Algorithm: Running with 2 for loops, sorting the array based on it's values*/
void Insert(BOOL(*f)(void*, void*), void* Element, void** Parray)
{
  int itt, jtt;
  void* temp;
  for (itt = 0; itt < CurrentCount; itt++)
  {
		if (!f(Element, Parray[itt]))
		{
			for (jtt = itt; jtt < CurrentCount; jtt++)
			{
				temp = Parray[jtt];
				Parray[jtt] = Element;
				Element = temp;
			}
		}
	}
	Parray[CurrentCount] = Element;
	CurrentCount++;
	return;
}
