/****************************
*╦ ╦╔╗╔╦╦  ╦╔═╗╦═╗╔═╗╦╔╦╗╦ ╦*
*║ ║║║║║╚╗╔╝║╣ ╠╦╝╚═╗║ ║ ╚╦╝*
*╚═╝╝╚╝╩ ╚╝ ╚═╝╩╚═╚═╝╩ ╩  ╩ *
****************************/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct student //Structures declaration
{
	char* name;
	long id;
	float exam;
	char marks[6];
	char final;
}student;

typedef struct university
{
	student* stud;
	int studsCount;
}university;

void menu(); //Functions declaration
void errMsg(char* msg);
void freeAll(university* u, int len);
void blcklst(university* u, int len, FILE* out);
void passFlag(FILE* out, university u, int len);
void functionC(FILE* out, university u, student* s, int len);
int countOnes(student* s);
int getData(FILE* in, university* u);
float avg(university* u, int len);
float maxG(university* u, int len);
float minG(university* u, int len);
float stdDev(university* u, int len, float avg);

int main()
{
	FILE* in, * out; //Program variables
	char func = '~';
	int flag = 0, len = 0;
	university u;
	student s;
	((in = fopen("input.txt", "r")) == NULL) ? errMsg("Couldn't find input.txt, ending program") : 0; //Opening files
	((out = fopen("output.txt", "w")) == NULL) ? errMsg("Couldn't open output.txt, ending program") : 0;
	menu();
	while (func != 'a') //A Function must be selected first
	{
		scanf("%c", &func);
		rewind(stdin);
		(func == 'a') ? len = getData(in, &u) : printf("You have to pick function A first!\nPlease pick function A: ");
	}
	printf("Function A applied successfully!\n\n");
	while (flag == 0)
	{
		menu();
		scanf("%c", &func);
		rewind(stdin);
		switch (func)
		{
			case 'a':
			{
				printf("You already picked function A, please choose another function:\n\n ");
				break;
			}
			case 'b':
			{
				fprintf(out, "OPTION B:\n");
				passFlag(out, u, len);
				printf("Function B applied successfully!\n\n");
				break;
			}
			case 'c':
			{
				fprintf(out, "OPTION C:\n");
				fprintf(out, "BEFORE: \n");
				passFlag(out, u, len);
				fprintf(out, "AFTER: \n");
				functionC(out, u, &s, len);
				printf("Function C applied successfully!\n\n");
				break;
			}
			case 'd':
			{
				fprintf(out, "OPTION D:\n");
				fprintf(out, "STATISTICS:\n");
				fprintf(out, "The average is: %.2f\n", avg(&u, len));
				fprintf(out, "The standard deviation is: %.2f\n", stdDev(&u, len, avg(&u, len)));
				fprintf(out, "The number of students are: %d\n", len);
				fprintf(out, "The range is: %.2f - %.2f\n", maxG(&u, len), minG(&u, len));
				printf("Function D applied successfully!\n\n");
				break;
			}
			case 'e':
			{
				fprintf(out, "OPTION E:\n");
				fprintf(out, "BLACKLIST: \n");
				blcklst(&u, len, out);
				printf("Function E applied successfully!\n\n");
				break;
			}
			case 'f':
			{
				fprintf(out, "\nEnd Of Program\n");
				printf("Function F applied successfully!\n\nTerminate program!");
				flag = 1;
				break;
			}
			default:
			{
				printf("Wrong input, please try again (B-F):\n\n ");
			}
		}
	}
	fclose(in);
	fclose(out);
	freeAll(&u, len);
	return 0;
}

/*Function name: menu
Input: None
Output: None
Algorithm: Printing program's menu*/
void menu()
{
	printf("Choose a function from the list below:\n");
	printf("a -> Retrieve students information from file, this function must be your first choose!\n");
	printf("b -> Print students information to output file\n");
	printf("c -> Print students information with final grade to output file\n");
	printf("d -> Print students statistics to output file\n");
	printf("e -> Print course blacklist to output file\n");
	printf("f -> Terminate Program\n");
	printf("Selected function: ");
}

/*Function name: errMsg
Input: None
Output: None
Algorithm: Printing error message and terminate program*/
void errMsg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}

/*Function name: freeAll
Input: university structure and number of students
Output: None
Algorithm: Running with for loop, release memory allocated by the program*/
void freeAll(university* u, int len)
{
	int itt = 0; //Function variable
	for (; itt < len; itt++)
	{
		free(u->stud[itt].name);
	}
	free(u->stud);
}

/*Function name: blcklst
Input: university structure, number of students and output file
Output: None
Algorithm: Running with for loop, each student with bad final grade will be printed to output file*/
void blcklst(university* u, int len, FILE* out)
{
	int itt = 0, jtt = 0; //Function variables
	for (; itt < len; itt++)
	{
		if (u->stud[itt].final == 0)
		{
			jtt++;
			fprintf(out, "Student %d: %s, %ld", jtt, u->stud[itt].name, u->stud[itt].id);
		}
	}
}

/*Function name: passFlag
Input: Output file, university structure and number of students
Output: None
Algorithm: Running with for loop, printing each student status to output file*/
void passFlag(FILE* out, university u, int len)
{
	int itt = 0;
	for (; itt < len; itt++)
	{
		fprintf(out, "Student %d: %s  %ld  %.2f %d\n", itt+1, u.stud[itt].name, u.stud[itt].id, u.stud[itt].exam, u.stud[itt].final);
	}
}

/*Function name: functionC
Input: Output file, university structure and number of students
Output: None
Algorithm: Running with for loop, printing students final grade after calculation*/
void functionC(FILE* out, university u, student* s, int len)
{
	int itt = 0; //Function variable
	for (; itt < len; itt++)
	{
		fprintf(out, "Student %d: %s  %ld  %.2f %d ", itt+1, u.stud[itt].name, u.stud[itt].id, u.stud[itt].exam, u.stud[itt].final); //Printing students to output file
		u.stud[itt].exam < 55 ? fprintf(out, "final: %.2f\n", u.stud[itt].exam) : 0; //Logic test for failed students
		u.stud[itt].final == 1 ? fprintf(out, "final: %.2f\n", (u.stud[itt].exam * 0.85) + (100 * 0.15)) : fprintf(out, "final: %.2f\n", u.stud[itt].exam); //Logic test for calculation final grade
	}
}

/*Function name: countOnes
Input: Pointer to specific student
Output: Integer represent number of passed assignments
Algorithm: Running with for loop, counting how many '1' appear in the string*/
int countOnes(student* s)
{
	int itt = 0, counter = 0, grade = 0; //Function variables
	for (; itt < 5; itt++)
	{
		grade = s->marks[itt];
		grade == '1' ? counter++ : 0;
	}
	return (counter >= 3) ? 1 : 0;
}

/*Function name: getData
Input: Input file and university structure
Output: Integer represent number of students in the university
Algorithm: Running with while loop, retrieving data from input file*/
int getData(FILE* in, university* u)
{
	int size = 1, itt = 0, jtt = 0;
	char temp[MAX];
	u->studsCount = size;
	u->stud = (student*)malloc(sizeof(student));
	(u->stud == NULL) ? errMsg("Memory allocation failed, terminate program") : 0;
	while ((fscanf(in, "%s %ld %f %s ", temp, &u->stud[itt].id, &u->stud[itt].exam, u->stud[itt].marks) != EOF))
	{
		u->stud[itt].final = countOnes(&u->stud[itt]);
		u->stud[itt].name = (char*)malloc((strlen(temp)+1)*sizeof(char));
		if (!u->stud[itt].name)
		{
			for (; jtt < itt; jtt++)
			{
				free(u->stud[jtt].name);
			}
			free(u->stud);
			errMsg("Memory allocation failed, terminate program");
		}
		strcpy(u->stud[itt].name, temp);
		u->stud = (student*)realloc(u->stud,(++size)*sizeof(student));
		if (!u->stud)
		{
			for (jtt = 0; jtt < itt; jtt++)
			{
				free(u->stud[jtt].name);
			}
			free(u->stud);
			errMsg("Memory allocation failed, terminate program");
		}
		itt++;
	}
	u->studsCount--;
	u->stud = (student*)realloc(u->stud,(size-1)*sizeof(student));
	if (!u->stud)
	{
		for (jtt = 0; jtt < itt; jtt++)
		{
			free(u->stud[jtt].name);
		}
		free(u->stud);
		errMsg("Memory allocation failed, terminate program");
	}
	return itt;
}

/*Function name: avg
Input: university structure and number of students
Output: Average course mark
Algorithm: Running with for loop, calculate the avg*/
float avg(university* u, int len)
{
	int itt = 0; //Function variables
	float sum = 0;
	for (; itt < len; itt++)
	{
		sum += u->stud[itt].exam; //First step
	}
	return (sum/len); //Last step
}

/*Function name: maxG
Input: university structure and number of students
Output: Highest score of the course
Algorithm: Running with for loop, finding the top*/
float maxG(university* u, int len)
{
	int itt = 1; //Function variables
	float max = u->stud[0].exam; //Set max to first student
	for (; itt < len; itt++)
	{
		max < u->stud[itt].exam ? max = u->stud[itt].exam : 0; //Logic test to find highest score
	}
	return max;

}

/*Function name: minG
Input: university structure and number of students
Output: Lowest score of the course
Algorithm: Running with for loop, finding the bottom*/
float minG(university* u, int len)
{
	int itt = 1; //Function variables
	float min = u->stud[0].exam; //Set min to first student
	for (; itt < len; itt++)
	{
		min > u->stud[itt].exam ? min = u->stud[itt].exam : 0; //Logic test to find lowest score
	}
	return min;
}

/*Function name: stdDev
Input: university structure and students avg
Output: Course's standard deviation
Algorithm: Running with for loop and calculate standard deviation*/
float stdDev(university* u, int len, float avg)
{
	int itt = 0; //Function variables
	float temp = 0;
	for (; itt < len; itt++)
	{
		temp += pow((u->stud[itt].exam - avg),2); //First step
	}
	temp /= len; //Second step
	return sqrt(temp); //Last step
}
