#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct //Structure declaration
{
  char name[20];
  int grades[3];
}student;

int InputData(student** p_array, FILE *fp); //Function declaration
void OutputData(int arr_size, student *arr, FILE* fp);
void Error_Msg(char* msg);

int main()
{
	FILE *fp; //Program Variables
	student *arr;
  int size;
  (fp = fopen("Students.txt", "rt")) ? 0 : Error_Msg("The input file is wrong"); //Opening file and exit if failed
  size = InputData(&arr, fp); //Reciving number of students
  fclose(fp); //Closing file
  (fp = fopen("Students.txt", "wt")) ? 0 : Error_Msg("The output file is wrong"); //Opening file and exit if failed
	OutputData(size, arr, fp); //Updating the text file with student's name and his heighst grade
  fclose(fp); //Closing file
  free(arr);
  return 0;
}

/*Function name: InputData
Input: Double pointer for first slot of the array and text file
Output: Integer represent number of students
Algorithm: Creating temp array copying data from file, counting each itteration*/
int InputData(student** p_array, FILE *fp)
{
 student *arr; //Function variables
 student *temp;
 int itt = 1;
 arr = (student*)malloc(sizeof(student));
 while(fscanf(fp, "%s %d %d %d", arr[itt-1].name, &arr[itt-1].grades[0], &arr[itt-1].grades[1], &arr[itt-1].grades[2]) != EOF)
 {
   itt++;
   temp = (student*)realloc(arr, sizeof(student)*itt); //Allocated memory for temp array
   temp == NULL ? Error_Msg("Memory Error") : 0; //Memory allocation failed
   arr = temp;
 }
 *p_array = arr;
  return (itt - 1); //Return the number of students
}

/*Function name: OutputData
Input: Integer represent array size, students array and text file
Output: None
Algorithm: Running with two loops, one for students and one for grades; finding maximum for each student*/
void OutputData(int arr_size, student *arr, FILE* fp)
{
  int itt, jtt = 0, max; //Function variables
  while (jtt < arr_size)
  {
    max = arr[jtt].grades[0]; //Setting max to first grade
    for (itt = 1; itt < 3; itt++) //Running on each grade, checking if it's higher
    {
      (arr[jtt].grades[itt] > max) ? max = arr[jtt].grades[itt] : 0; //Updating max if needed
    }
    fprintf(fp, "%s %d\n", arr[jtt].name, max); //Writing back to the file, name and max grade
    jtt++;
  }
  fclose(fp);
}

/*Function name: Error_Msg
Input: Pointer to the first letter of a charcters array
Output: None
Algorithm: Printing error and exit*/
void Error_Msg(char* msg)
{
	printf("\n%s", msg);
	exit(1);
}
