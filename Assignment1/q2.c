/**********************************
*╔╦╗╔═╗╔═╗╔═╗╦═╗╔╦╗╔╦╗╔═╗╔╗╔╔╦╗╔═╗*
* ║║║╣ ╠═╝╠═╣╠╦╝ ║ ║║║║╣ ║║║ ║ ╚═╗*
*═╩╝╚═╝╩  ╩ ╩╩╚═ ╩ ╩ ╩╚═╝╝╚╝ ╩ ╚═╝*
***********************************/

#define _CRT_SECURE_NO_WARNINGS
#define N 3
#define MAX 21
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct department //Structures declaration
{
  char code[11];
  char* name;
  int sold;
}dept;

void data(dept* store); //Function declaration
void bSort(dept* store, dept* deptsPt[]);
void freeDepts(dept* depts);
void swap(dept* stPt, dept* ndPt);

int main()
{
  dept store[N]; //Program variables
  dept* deptsPt[N];
  int itt = 0;
  N == 1 ? (printf("There's only one deparment in the store, no need to evaluate"), exit(0)) : 0;
  printf("Departments Evaluation Program!\n");
  data(store); //Retrieving data from user
  for (; itt < N; itt++) //Copying address to pointers array
  {
    deptsPt[itt] = &store[itt];
  }
  bSort(store, deptsPt);
  freeDepts(store); //Release memory aloocated by the program
  return 0;
}

/*Function name: data
Input: Array of departments
Output: None
Algorithm: Retrieving data from user with for loop*/
void data(dept* store)
{
  char name[MAX]; //Function variables
  int itt = 0, flag;
  for (; itt < N; itt++)
  {
    printf("\nEnter department #%d details\n", itt+1);
    printf("Enter department code: ");
    scanf("%s", store[itt].code);
    printf("Enter department name: ");
    scanf("%s", name); //Holding name on temporary variable
    assert(store[itt].name = (char*)malloc((strlen(name)+1)*sizeof(char))); //Validating memory allocation
    strcpy(store[itt].name, name); //Copying name into dept.name
    do //Do while loop, validating sold amount
    {
      rewind(stdin); //Reset input, avoiding infinite loop
      printf("Enter number of sold units: ");
      flag = ((scanf("%d", &store[itt].sold) == 1) && (store[itt].sold >= 0)); //Logic test for sold amount to be a positive integer
      flag == 0 ? printf("Sold products must be a positive integer.\n") : 0; //Error printing if necessary
    }
    while (flag == 0); //If test failed, retuning to another round
  }
}
/*Function name: bSort
Input: Array of departments and pointers array pointed to each department
Output: None
Algorithm: Bubble sorting the array and print worset and best department*/
void bSort(dept* store, dept* deptsPt[])
{
  int itt, jtt; //Function variables
  for (itt = 0; itt < N-1; itt++)
  {
    for (jtt = 0; jtt < N-itt-1; jtt++)
    {
      store[jtt].sold > store[jtt+1].sold ? swap(deptsPt[jtt], deptsPt[jtt+1]) : 0;
    }
  }
  printf("\nThe most unsuccessful department is: %s %s\nThe most successful department is: %s %s",  deptsPt[0]->name, deptsPt[0]->code, deptsPt[N-1]->name, deptsPt[N-1]->code);
}
/*Function name: freeDepts
Input: Array of departments
Output: None
Algorithm: Running with for loop, release allocated memory by program*/
void freeDepts(dept* store)
{
  int itt = 0; //Function variable
  for (; itt < N; itt++) //Releasing memory allocated by program
  {
    free(store[itt].name);
  }
}
/*Function name: swap
Input: Two pointers
Output: None
Algorithm: Holding the first pointer with a temporary variable and swaping*/
void swap(dept* stPt, dept* ndPt)
{
  dept temp = *stPt; //Function variable
  *stPt = *ndPt; //Swaping
  *ndPt = temp;
}
