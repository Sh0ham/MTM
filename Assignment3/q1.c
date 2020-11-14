/**********************************************
____ ____ ____ ___ ____ _  _ ____ ____ _  _ ___
|__/ |___ [__   |  |__| |  | |__/ |__| |\ |  |
|  \ |___ ___]  |  |  | |__| |  \ |  | | \|  |
**********************************************/
#include "rest.h"

int main()
{
	int tblQunt, itt = 0, check, opt;
	int qunt, price, tblNum;
	char product[50];
	FILE* Manot, * Inst, * output;
	PKtchn p = NULL;
	PTabl tblArr;
	((output = fopen("output.txt", "wt")) == NULL) ? printf("Error creating output.txt file"), exit(1) : 0;
	((Inst = fopen("Instructions.txt", "rt")) == NULL) ? printf("Error reading instructions.txt file"), exit(1) : 0;
	fscanf(Inst, "%d", &tblQunt);
	tblArr = (PTabl)malloc(tblQunt * sizeof(Table));
	tblArr == NULL ? free(tblArr), errMsg(output, "Memmory allocation failed") : 0;
	for (; itt < tblQunt; itt++)
	{
		tblArr[itt].bill = 0;
		tblArr[itt].tblNum = itt;
		tblArr[itt].orders = NULL;
	}
	while (fscanf(Inst, "%d", &opt) == 1)
	{
		switch (opt)
		{
			case 1:
			{
				Manot = fopen("Manot.txt", "rt");
				Manot == NULL ? errMsg(output, "Memmory allocation failed") : 0;
				crtPrdcts(output,Manot, &p);
				fclose(Manot);
				break;
			}
			case 2:
			{
				fscanf(Inst, "%s %d", product, &qunt);
				addItms(output,product, qunt, &p);
				break;
			}
			case 3:
			{
				fscanf(Inst, "%d %s %d", &tblNum, product, &qunt);
				ordrItm(output,tblNum, product, qunt, tblQunt, tblArr, &p);
				break;
			}
			case 4:
			{
				fscanf(Inst, "%d %s %d", &tblNum, product, &qunt);
				rmvItm(output,tblNum, product, qunt, tblQunt, tblArr);
				break;
			}
			case 5:
			{
				fscanf(Inst, "%d", &tblNum);
				rmvTbl(output,tblNum, tblQunt, tblArr, &p);
				break;
			}
			default:
			{
				fprintf(output,"\nThere's no such command\n");
				break;
			}
		}
	}
	fclose(output);
	fclose(Inst);
	free(tblArr);
	return 0;
}
