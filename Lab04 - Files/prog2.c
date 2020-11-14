#define _CRT_SECURE_NO_WARNINGS
#define COURSE 4
#define ID 5
#define MAX_NAME 17
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct student //Structures declaration
{
  char course[COURSE];
  char id[ID];
  char name[MAX_NAME];
}student;

void Find(FILE *fp, char *course); //Function declaration
void Get_Lost(char *s);
int myAtoi(char* str);
char* myItoa(int num, char* buffer, int base) ;

int main()
{
  char course[COURSE];
  FILE *file;
  (file = fopen("Stud.txt", "rt")) ? 0 : Get_Lost("Cannot open file");
  printf("Enter the name of course, up to 3 letters: ");
  scanf("%s", course);
  Find(file, course);
  fclose(file);
  return 0;
}

/*Function name: Find
Input: File and course name
Output: None
Algorithm: Open a new text file with details of the coruse students*/
void Find(FILE *fp, char *course)
{
	student stud; //Function Variables
	char courseName[COURSE*2];
	char id[MAX_NAME];
	FILE *out;
	strcpy(courseName, course); //Copying course name
	strcat(courseName, ".txt"); //Combine it with .txt end
	(out = fopen(courseName, "wt")) ? 0 : Get_Lost("Cannot open file");
	while (fgets(stud.course, COURSE, fp) != NULL)
	{
		fgets(stud.id, ID, fp);
		fgets(stud.name, MAX_NAME, fp);
		myItoa(myAtoi(stud.id), id, 2);
		(strcmp(stud.course, course) == 0) ? fprintf(out, "%s, %s, %s\n", id, stud.name, stud.course) : 0;
	}
	fclose(out); //Close file
}

/*Function name: Get_Lost
Input: Pointer to the first letter of a charcters array
Output: None
Algorithm: Printing error and exit*/
void Get_Lost(char *s)
{
	puts(s);
	exit(1);
}

/*Function name: myAtoi
Input: Pointer to the first letter of a charcters array
Output: Integer value of given string
Algorithm: Implementation of atoi function for UNIX based OS*/
int myAtoi(char* str)
{
    int num = 0, itt = 0;
    for (; str[itt] != '\0'; ++itt)
    {
      num = num * 10 + str[itt] - '0';
    }
    return num;
}

/*Function name: myItoa
Input: Integer number, a string and desired base
Output: Pointer to the first letter of the string
Algorithm: Implementation of itoa function for UNIX based OS*/
char* myItoa(int num, char* buffer, int base)
{
  int curr = 0, num_digits = 0, base_val, num_val;
  char value;
  if (num == 0)
  {
    buffer[curr++] = '0';
    buffer[curr] = '\0';
    return buffer;
  }
  if (num < 0)
  {
    if (base == 10)
    {
      num_digits++;
      buffer[curr] = '-';
      curr++;
      num *= -1;
    }
    else
    {
      return NULL;
    }
  }
  num_digits += (int)floor(log(num)/log(base))+1;
  while (curr < num_digits)
  {
    base_val = (int)(pow(base, num_digits-1-curr));
    num_val = num / base_val;
    value = num_val + '0';
    buffer[curr] = value;
    curr++;
    num -= base_val * num_val;
  }
  buffer[curr] = '\0';
  return buffer;
}
