#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Person //Structure declaration
{
	char ID[10];
	char F_name[11];
	char L_name[16];
	int Age;
	char Addr[51];
}Person;

void Error_Msg(char* msg); //Function declaration

int main()
{
	Person temp; //Program Variables
	FILE *in, *out;
	(in = fopen("the_first.txt", "rt")) ? 0 : Error_Msg("File didn't open successfully"); //Opening file and exit if failed
	(out = fopen("the_second.txt", "wt")) ? 0 : Error_Msg("File didn't open successfully"); //Opening file and exit if failed
	fscanf(in, "%s %s %s %d %s", temp.ID, temp.F_name, temp.L_name, &temp.Age, temp.Addr); //Reading values into structe
	fprintf(out, "ID: %s\nFull name: %s %s\nAge: %d\nAddress: %s", temp.ID, temp.F_name, temp.L_name, temp.Age, temp.Addr); //Writing values into the new file
	fclose(in); //Closing files
	fclose(out);
	return 0;
}

/*Function name: Error_Msg
Input: Pointer to the first letter of a charcters array
Output: None
Algorithm: Printing error and exit*/
void Error_Msg(char* msg)
{
	printf("\n%s", msg); //Printing error message
	exit(1);
}
