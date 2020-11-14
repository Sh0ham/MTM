#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FALSE,
  TRUE
}BOOL;

BOOL IsFull(); //Functions declaration
BOOL intComp(void *FirstElement, void *SecondElement);
void Insert(BOOL(*f)(void *, void *), void *Element, void ** Parray);

int CurrentCount = 0;

int main()
{
  int Array[N], Value, itt; //Program variables
  void* PArray[N];

  printf("Enter numbers, -999 to stop: ");
  scanf("%d", &Value);
  while(Value != -999)
  {
    if(!IsFull())
    {
        Array[CurrentCount] = Value;
        Insert(intComp, &Array[CurrentCount], PArray);
        scanf("%d", &Value);
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
   printf("%d ", *(int*)PArray[itt]);
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

/*Function name: intComp
Input: Two pointers
Output: True or False
Algorithm: Comparing values*/
BOOL intComp(void *FirstElement, void *SecondElement)
{
  return (*(int*)FirstElement > *(int*)SecondElement) ? TRUE : FALSE;
}

/*Function name: Insert
Input: Function pointer, double pointer and pointer
Output: None
Algorithm: Running with 2 for loops, sorting the array based on it's values*/
void Insert(BOOL(*f)(void*, void*), void* Element, void** Parray)
{
	int itt = 0, jtt;
	void* temp;
	for (; itt < CurrentCount; itt++)
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
