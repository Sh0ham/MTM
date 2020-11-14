#include "tree.h"

struct tree //Structures initialization
{
	void* key;
	struct tree* right;
	struct tree* left;
};

void addTree(FILE* out, Ptree* tree, Ptree* STree, void* newKey, int count, option (*cmpInt)(void* elemnt1, void* elemnt2), void(*freeKey)(void* key))
{

	int check;
	if ((*tree) == NULL)
	{
		*tree = createTree(newKey);
		count == 0 ? STree = tree : 0;
		if (*tree == NULL)
		{
			fprintf(out, "\nAllocation tree node failed");
			emptyTree(*STree, freeKey);
			exit(1);
		}
	}
	else
	{
		check = cmpInt(newKey, (*tree)->key);
		if (check == 0)
		{
			fprintf(out, "\nThis key already exists in the tree");
		}
		else
		{
			count++;
			check == 1 ? addTree(out, &((*tree)->left), STree, newKey, count, cmpInt, freeKey) : addTree(out, &((*tree)->right), STree, newKey, count, cmpInt, freeKey);
		}
	}
}

Ptree createTree(void* key)
{
	Ptree newTree;
	newTree = (Ptree)malloc(sizeof(struct tree));
	if (newTree == NULL)
	{
		printf("Memory allocation failed");
		exit(1);
	}
	else
	{
		newTree->key = key;
		newTree->left = NULL;
		newTree->right = NULL;
	}
	return newTree;
}

void emptyTree(Ptree root, void(*freeKey)(void* key))
{
	if (root == NULL)
	{
		return;
	}
	emptyTree(root->left, freeKey);
	emptyTree(root->right, freeKey);
	freeKey(root->key);
	freeKey(root);
}

void printInOrder(Ptree root, void(*PRINT_ELEMENT)(FILE*, void*), FILE* out)
{
	if (root == NULL)
	{
		return;
	}
	printInOrder(root->left, PRINT_ELEMENT, out);
	PRINT_ELEMENT(out, root->key);
	printInOrder(root->right, PRINT_ELEMENT, out);
}

int treeHeight(Ptree tree)
{
	int left, right;
	if (tree == NULL)
	{
		return -1;
	}
	else
	{
		left = treeHeight(tree->left);
		right = treeHeight(tree->right);
		return left > right ? (left+1) : (right+1);
	}
}

void max(Ptree tree, void(*PRINT_ELEMENT)(FILE*, void*), FILE* out)
{
	Ptree temp;
	temp = tree;
	!temp ? fprintf(out, "\nNo value on tree!") : 0;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	fprintf(out, "\nThe maximum is ");
	PRINT_ELEMENT(out, temp->key);
}

int printSmallest(Ptree tree, void(*PRINT_ELEMENT)(FILE*, void*), int k, FILE* out)
{
	if (tree == NULL)
		return k;
	k = printSmallest(tree->left, PRINT_ELEMENT, k, out);
	if (k > 0)
	{
		PRINT_ELEMENT(out, tree->key);
		k--;
	}
	k = printSmallest(tree->right, PRINT_ELEMENT, k, out);
	return k;
}
