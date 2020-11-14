#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student //Structure declaration
{
	char *name;
	int marks[4];
	float avg;
}Student;

Student* Create_Class(int size); //Functions declaration
void Avg_Mark(Student* s);
void Print_One(Student* s);

int main()
{
	int size, itt; //Variables declaration
	Student *arr;
	printf("Enter the number of students: "); //Retrieving data
	scanf("%d", &size);
	arr = Create_Class(size); //Creating class by function into the array
	printf("\n");
	for (itt = 0; itt < size; itt++) //Running on the class slots
	{
		(arr[itt].avg > 85) ? (Print_One(arr+itt), printf("\n")) : 0; //Printing relevant Students
	}
	for (itt = 0; itt < size; itt++) //Free memory allocated by the program loop
	{
		free(arr[itt].name);
	}
	free(arr); //Free class array allocated by the program
	return 0;
}

/*Function name: Create_Class
Input: Integer represent amount of Students
Output: Pointer to the Class array first slot
Algorithm: */
Student* Create_Class(int size)
{
	int itt, jtt, num = 4; //Function variables
	char tempName[51]; //Temp name set to fill max of 50 charcters
	Student *Class = (Student *)malloc(sizeof(Student)*size); //Allocating memory for class array
	Class == NULL ? exit(1) : 0; //Allocated memory failed
	for (itt = 0; itt < size; itt++) //Running with for loop setting names with appropriate string length
	{
		char *name; //Pointer to first letter to be used as Student's name
		rewind(stdin); //Clean input
		printf("Enter your name: "); //Retrieving data
		gets(tempName);
		name = (char *)malloc((strlen(tempName)+1)*sizeof(char)); //Allocating memory for name strings
		name == NULL ? exit(1) : 0; //Allocated memory failed
		strcpy(name, tempName); //Copying name from temporary name string
		Class[itt].name = name; //Setting Student's name to class structure Student card
		printf("Enter your marks: "); //Retrieving data
		for (jtt = 0; jtt < num; jtt++)
		{
			scanf("%d", &Class[itt].marks[jtt]); //Setting it's grades to structure slots
		}
		Avg_Mark(Class+itt); //Setting it's average data to Student
	}
	return Class;
}

/*Function name: Avg_Mark
Input: Pointer to the slot of Students structure array
Output: None
Algorithm: Setting every Student it's average*/
void Avg_Mark(Student* s)
{
	int itt, sum; //Function variables
	for (itt = 0; itt < 4; itt++) //Running on each slot setting it's marks
	{
		sum += s->marks[itt];
	}
	s->avg = (double)sum/4; //Calculating average
}
/*Function name: Print_One
Input: Pointer to the slot of Student structure array
Output: None
Algorithm: Printing it's name and average*/
void Print_One(Student* s)
{
	printf("The average of %s is %.1f", s->name, s->avg); //Printing name and average rounded to first decimal point
}
