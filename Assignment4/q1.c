/**************************************
$$$$$$$$\
\__$$  __|
   $$ | $$$$$$\   $$$$$$\   $$$$$$\
   $$ |$$  __$$\ $$  __$$\ $$  __$$\
   $$ |$$ |  \__|$$$$$$$$ |$$$$$$$$ |
   $$ |$$ |      $$   ____|$$   ____|
   $$ |$$ |      \$$$$$$$\ \$$$$$$$\
   \__|\__|       \_______| \_______|
**************************************/
#include "tree.h"

void freeKey(void* key);
void printInt(FILE* out, void* key);
option cmpInt(void* elemnt1, void* elemnt2);

int main()
{
	int count = 0, check = 0, num, cmd, *Val;
	Ptree root = NULL, temp;
	FILE *in, *out;
	((in = fopen("Instructions.txt", "rt")) == NULL) ? printf("Error reading instructions.txt file"), exit(1) : 0;
	((out = fopen("output.txt", "wt")) == NULL) ? printf("Error creating output.txt file"), exit(1) : 0;
	while (fscanf(in, "%d", &num) != EOF)
	{
		switch (num)
		{
			case 1:
			{
				((Val = (int*)malloc(sizeof(int))) == NULL) ? printf("Memory allocation failed"), exit(1) : 0;
				fscanf(in, "%d", &cmd);
				*Val = cmd;
				addTree(out, &root, &root, Val, check, cmpInt, freeKey);
				fprintf(out, "\n%d was added to the tree", cmd);
				check = 0;
				count++;
				break;
			}
			case 2:
			{
				fprintf(out, "\nThe tree sorted by inorder:\n");
				printInOrder(root, printInt, out);
				break;
			}
			case 3:
			{
				fprintf(out, "The hight of your tree is %d", treeHeight(root));
				break;
			}
			case 4:
			{
				max(root, printInt, out);
				break;
			}
			case 5:
			{
				fscanf(in, "%d", &cmd);
				if (cmd <= count)
				{
				fprintf(out, "\nThere are %d smallest elements in this tree: ", cmd);
				cmd = printSmallest(root, printInt, cmd, out);
				}
				else
				{
					fprintf(out, "\nThere are no %d elements in this tree", cmd);
				}
				break;
			}
			default:
			{
				fprintf(out, "\nThis order does not exist");
			}
		}
	}
	emptyTree(root, freeKey);
	fclose(in);
	fclose(out);
	return 0;
}

void freeKey(void* key)
{
	free(key);
}

void printInt(FILE* out, void* key)
{
	fprintf(out, "%d ", *(int*)key);
}

option cmpInt(void* elemnt1, void* elemnt2)
{
	if (*(int*)elemnt1 == *(int*)elemnt2)
	{
		return equal;
	}
	return (*(int*)elemnt1 < *(int*)elemnt2) ? bigger : smaller;
}
