#include "rest.h"

/*Function Name: errMsg
Input: File and a string
Output: None
Algorithm: Printing error to file and terminate the program*/
void errMsg(FILE* out, char* msg)
{
	fprintf(out,"\n%s", msg);
	exit(1);
}

/*Function Name: crtPrdcts
Input: Two files and kitchen pointer
Output: None
Algorithm: Scanning products data from "Manot.txt" file to kitchen structrue*/
void crtPrdcts(FILE* out, FILE* in, PKtchn* p)
{
	PKtchn hodl;
	Kitchen* temp;
	char tmp[51];
	int len, flag = 0;
	hodl = *p;
	temp = (Kitchen*)malloc(sizeof(Kitchen));
	temp == NULL ? free(temp), errMsg(out, "Memmory allocation failed") : 0;
	while (fscanf(in, "%s %d %d", tmp, &temp->quantity, &temp->Price) == 3)
	{
		if (temp->Price <= 0)
		{
			free(temp->prdctName);
			free(temp);
			fprintf(out,"\nThe price of %s must be a positive number.\n", tmp);
			flag = 1;

		}
		if (temp->quantity <= 0)
		{
			free(temp->prdctName);
			free(temp);
			fprintf(out, "\nThe quantity of %s must be a positive number.\n", tmp);
			flag = 1;
		}
		if (*p != NULL)
		{
			while (hodl)
			{
				if (strcmp(hodl->prdctName, tmp) == 0)
				{
					fprintf(out,"It seems that the product %s is already exists in the kitchen!\n", tmp);
					free(temp->prdctName);
					free(temp);
					hodl = NULL;
					flag = 1;
				}
				else
				{
					hodl = hodl->next;
				}
			}
		}
		len = strlen(tmp);
		temp->prdctName = (char*)malloc((len + 1) * sizeof(char));
		temp == NULL ? free(temp), errMsg(out, "Memmory allocation failed") : 0;
		strcpy(temp->prdctName, tmp);
		temp->Maxquantity = 0;
		if (flag == 0)
		{
			if (*p == NULL)
			{
				*p = temp;
				(*p)->next = NULL;
			}
			else
			{
				temp->next = *p;
				*p = temp;
			}
			fprintf(out,"Successfully added \"%s\" as a new product to the list (quantity = %d, price = %d)\n", temp->prdctName, temp->quantity, temp->Price);
		}
		flag = 0;
		hodl = *p;
		temp = (Kitchen*)malloc(sizeof(Kitchen));
		temp == NULL ? free(temp), errMsg(out, "Memmory allocation failed") : 0;
	}
	hodl = NULL;
}

/*Function Name: addItms
Input: File, string, integer and kitchen pointer
Output: None
Algorithm: Running with while loop, adding items to kitchen*/
void addItms(FILE* out, char* prod, int q, PKtchn* ptr)
{
	PKtchn p;
	int flag = 0;
	p = *ptr;
	while (flag == 0)
	{
		if (p == NULL)
		{
			flag = 1;
			fprintf(out, "%s does not exist, please try again!\n", prod);
			return;
		}
		if (strcmp(p->prdctName, prod) == 0)
		{
			flag = 1;
			if (q <= 0)
			{
				fprintf(out, "%s doesn't have a valid quantity!\n", prod);
				return;
			}
			p->quantity += q;
		}
		else
		{
			p = p->next;
		}
	}
}

/*Function Name: rmvTbl
Input: 2 integers, array and kitchen pointer
Output: None
Algorithm: Printing table details and release allocated memory for the  table*/
void rmvTbl(FILE* out, int tblNum, int MaxTablesNum, PTabl array, PKtchn* k)
{
	int counter = 0, itt = 0, max = 0, len = 0;
	char favDish[50];
	POrdr temp = NULL;
	if (tblNum > MaxTablesNum || tblNum < 1)
	{
		fprintf(out, "Error, no table %d\n", tblNum);
		fprintf(out, "Please choose a table between 1 to %d", MaxTablesNum-1);
		return;
	}
	for (; itt < MaxTablesNum; itt++)
	{
		array[itt].orders != NULL ? counter++ : 0;
	}
	if (array[tblNum].bill == 0)
	{
		fprintf(out,"\nTable number %d hasn't ordered anything yet.\n", tblNum);
		return;
	}
	fprintf(out,"\n\n\t\t******************The bill*******************\n");
	fprintf(out,"\t\t****************Table No.%d*******************\n\n", tblNum);
	fprintf(out,"                    Dish\tQuantity\tTotal Price\n");
	while (array[tblNum].orders != NULL)
	{
		temp = array[tblNum].orders;
		fprintf(out, "\t\t    %s\t     %d\t\t   %d NIS\n", temp->prdctName, temp->quantity, temp->quantity * temp->Price);
		array[tblNum].orders = array[tblNum].orders->next;
		free(temp->prdctName);
		free(temp);
	}
	fprintf(out,"\n\n\t\t*************Total bill is: %d NIS************\n", array[tblNum].bill);
	array[tblNum].bill = 0;
	free(array[tblNum].orders);
	if (counter == 1)
	{
		while ((*k) != NULL)
		{
			if ((*k)->Maxquantity > max)
			{
				max = (*k)->Maxquantity;
				strcpy(favDish, (*k)->prdctName);
			}
			(*k) = (*k)->next;
		}
		fprintf(out, "\n\nEnd of the day report:\n");
		fprintf(out, "The most popular dish of the day was %s, with a total quantity of %d orders\n", favDish, max);
	}
	return;
}

/*Function Name: rmvItm
Input: File, 3 integers, string and array
Output: None
Algorithm: Removing item orderd by getting table number and a dish and delete the quantity ordered*/
void rmvItm(FILE* out, int tblNum, char* prdctName, int quantity, int MaxTablesNum, PTabl array)
{
	POrdr tmpOrdr;
	if (tblNum > MaxTablesNum || tblNum < 1)
	{
		fprintf(out, "Error, no such table %d\n", tblNum);
		fprintf(out, "Please choose a table between 0 to %d", MaxTablesNum-1);
		return;
	}
	if (quantity < 1)
	{
		fprintf(out, "You cannot remove %d items from the order.\nPlease type a positive quantity", quantity);
		return;
	}
	if (array[tblNum].orders != NULL)
	{
		while (array[tblNum].orders != NULL)
		{
			if (strcmp(prdctName, array[tblNum].orders->prdctName) == 0)
			{
				if (array[tblNum].orders->quantity < quantity)
				{
					fprintf(out, "You cannot cancel %d %ss since you ordered %d dishes\n", quantity, prdctName, array[tblNum].orders->quantity);
					return;
				}
				else
				{
					array[tblNum].bill -= quantity * array[tblNum].orders->Price;
					array[tblNum].orders->quantity -= quantity;
					fprintf(out, "Successfully removed %d %ss from the table number %d", quantity, prdctName, tblNum);
					return;
				}
				if (array[tblNum].orders->quantity == 0)
				{
					tmpOrdr = array[tblNum].orders;
					if (array[tblNum].orders->prev == NULL)
					{
						array[tblNum].orders->next->prev = NULL;
						array[tblNum].orders = array[tblNum].orders->next;
						fprintf(out, "Removing %s from table %d becuse the quantity is 0\n", prdctName, tblNum);
						free(tmpOrdr);
					}
					else if (array[tblNum].orders->next == NULL)
					{

						array[tblNum].orders->prev->next = NULL;
						array[tblNum].orders = array[tblNum].orders->prev;
						fprintf(out, "Removing %s from table %d becuse the quantity is 0\n", prdctName, tblNum);
						free(tmpOrdr);
					}
					else
					{
						array[tblNum].orders->prev->next = array[tblNum].orders->next;
						array[tblNum].orders->next->prev = array[tblNum].orders->prev;
						array[tblNum].orders = array[tblNum].orders->prev;
						fprintf(out, "Removing %s from table %d becuse the quantity is 0\n", prdctName, tblNum);
						free(tmpOrdr);
					}
				}
				fprintf(out, "Successfully removed %d %ss from table number %d", quantity, prdctName, tblNum);
				return;
			}
			array[tblNum].orders = array[tblNum].orders->next;
		}
	}
	fprintf(out, "Cannot find a order to delete. please order first\n");
	return;
}

/*Function Name: ordrItm
Input: File, 3 integers, string, array and kitech pointer
Output: None
Algorithm: Retrive data from table, checking up with kitech for quantity and add it as linked list*/
void ordrItm(FILE* out, int tblNum, char* prdctName, int quantity, int MaxTablesNum, PTabl array, PKtchn* p)
{
	PKtchn tmpKitchn;
	POrdr tmpOrdr;
	tmpKitchn = *p;
	if (tblNum > MaxTablesNum || tblNum < 1)
	{
		fprintf(out, "Error, No Table %d\n",tblNum);
		fprintf(out, "Please choose a table between 1 to %d", MaxTablesNum);
		return;
	}
	if (quantity < 1)
	{
		fprintf(out, "The quantity most be a positive number");
		return;
	}
	while (tmpKitchn)
	{
		if (strcmp(tmpKitchn->prdctName, prdctName) == 0)
		{
				if (tmpKitchn->quantity < quantity)
				{
					fprintf(out, "Error, not enough %s in stock\n", tmpKitchn->prdctName);
					return;
				}
				if (array[tblNum].orders == NULL)
				{
					array[tblNum].orders = (POrdr)malloc(sizeof(Order));
					array[tblNum].orders == NULL ? free(array[tblNum].orders), errMsg(out, "Memmory allocation failed\n") : 0;
					array[tblNum].orders->prdctName = (char*)malloc((strlen(prdctName) + 1) * (sizeof(char)));
					array[tblNum].orders->prdctName == NULL ? free(array[tblNum].orders->prdctName), free(array[tblNum].orders), errMsg(out, "Memmory allocation failed\n") : 0;
					strcpy(array[tblNum].orders->prdctName, prdctName);
					array[tblNum].orders->Price = tmpKitchn->Price;
					array[tblNum].orders->quantity = quantity;
					tmpKitchn->Maxquantity += quantity;
					array[tblNum].orders->next = NULL;
					array[tblNum].orders->prev = NULL;
					array[tblNum].bill = quantity * tmpKitchn->Price;
					tmpKitchn->quantity -= quantity;
					fprintf(out, "New table was opened (%d). first dish is %s, ordered %d times\n\n", tblNum, prdctName, quantity);
					return;
				}
				tmpOrdr = array[tblNum].orders;
				while (tmpOrdr)
				{
					if (strcmp(array[tblNum].orders->prdctName, prdctName) == 0)
					{
						tmpKitchn->Maxquantity += quantity;
						array[tblNum].orders->quantity += quantity;
						array[tblNum].bill += quantity * tmpKitchn->Price;
						tmpKitchn->quantity -= quantity;
						fprintf(out, "The quantity of %s in the table %d was updated from %d to %d\n\n", prdctName, tblNum, array[tblNum].orders->quantity, array[tblNum].orders->quantity + quantity);
						return;
					}
					tmpOrdr = tmpOrdr->next;
				}
				tmpOrdr = (Order*)malloc(sizeof(Order));
				tmpOrdr == NULL ? free(array[tblNum].orders), errMsg(out, "Memmory allocation failed\n") : 0;
				tmpOrdr->prdctName = (char*)malloc((strlen(prdctName) + 1) * sizeof(char));
				(tmpOrdr->prdctName == NULL) ? free(array[tblNum].orders->prdctName), free(array[tblNum].orders), errMsg(out, "Memmory allocation failed\n") : 0;
				strcpy(tmpOrdr->prdctName, prdctName);
				tmpOrdr->quantity = quantity;
				tmpOrdr->Price = tmpKitchn->Price;
				tmpOrdr->prev = NULL;
				tmpOrdr->next = array[tblNum].orders;
				array[tblNum].orders->prev = tmpOrdr;
				array[tblNum].bill += quantity * tmpKitchn->Price;
				tmpKitchn->quantity -= quantity;
				fprintf(out, "%d %s was added to the table %d \n\n", quantity, prdctName, tblNum+1);
		}
		tmpKitchn = tmpKitchn->next;
	}
	fprintf(out, "Can't add %s since it's not in the menu\n", prdctName);
}
