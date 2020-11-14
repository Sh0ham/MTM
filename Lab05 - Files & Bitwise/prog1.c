#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students //Structures declaration
{
  char name[7];
  char dept[5];
  char gradeSt[4];
  char gradeNd[4];
}stud;

void CopyComp(FILE* in, FILE* out); //Function declaration
void ErrorMsg(char* str);

int main()
{
  FILE *in, *out; //Program Variables
  (in = fopen("Students.txt", "rt")) ? 0 : ErrorMsg("Cannot open file"); //Opening file and exit if failed
  (out = fopen("StudentsNew.txt", "wt")) ? 0 : ErrorMsg("Cannot open file"); //Opening file and exit if failed
  CopyComp(in, out);
  fclose(in); //Closing files
  fclose(out);
  return 0;
}

/*Function name: CopyComp
Input: Two files
Output: None
Algorithm: Running with while loop, copying details*/
void CopyComp(FILE* in, FILE* out)
{
  stud stud; //Program Variables
  char str[5] = {"Comp"}; //Used for comparison
  int avgSt, avgNd;
  while (fgets(stud.name, 7, in) != NULL)
  {
    fgets(stud.dept, 5, in);
    fgets(stud.gradeSt, 4, in);
    fgets(stud.gradeNd, 4, in);
    if (strcmp(str, stud.dept) == 0) //Succeed comparing
    {
      avgSt = atoi(stud.gradeSt); //Converting grades into integers
      avgNd = atoi(stud.gradeNd);
      fprintf(out, "%s %.2f\n", stud.name, ((avgSt+avgNd)/2.0)); //Calculating average and printing it
    }
  }
}

/*Function name: ErrorMsg
Input: Pointer to the first letter of a charcters array
Output: None
Algorithm: Printing error and exit*/
void ErrorMsg(char* str)
{
  printf("\n%s", str);
  exit(1);
}
