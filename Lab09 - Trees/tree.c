#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0
#define Max(a,b) ((a) > (b) ? (a) : (b))

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int key;
	float val;
} Data;

typedef struct TreeNode
{
	struct TreeNode *left;
	struct TreeNode *right;
	Data TreeNode_info;
} TreeNode;

typedef struct ListNode
{
	struct ListNode *next;
	Data ListNode_info;
} ListNode;

void print_list(ListNode *);
void empty_list(ListNode **);
void empty_tree(TreeNode **);
void insert_info_by_key(TreeNode **,TreeNode **, Data);
int treeHight(TreeNode *);
float sum_tree(TreeNode *);
TreeNode *create_search_tree();
TreeNode *create_tree_node(Data);
ListNode *create_list_node(Data);
ListNode *append_lists(ListNode *, ListNode *);
ListNode *tree_to_inorder_list(TreeNode *);
ListNode *tree_to_preorder_list(TreeNode *);

int main()
{
	TreeNode *inputTree = NULL;
	ListNode *preList = NULL, *inList = NULL;
	printf("Getting the input tree");
	inputTree = create_search_tree();
	printf("\nHight of tree is %d", treeHight(inputTree));
	printf("\nSum of values of tree is %f", sum_tree(inputTree));
	printf("\nPrinting input tree inorder");
	inList = tree_to_inorder_list(inputTree);
	print_list(inList);
	printf ("\nPrinting input tree preorder");
	preList = tree_to_preorder_list(inputTree);
	print_list(preList);
	empty_tree(&inputTree);
	empty_list(&preList);
  empty_list(&inList);
	return 0;
}

/*Function name: print_list
Input: Pointer to head of the tree
Output: None
Algorithm: Running with while loop on each node*/
void print_list(ListNode *head)
{
	if (head == NULL)
	{
		printf("\nThe list is EMPTY\n");
		return;
	}
	printf("\nThe list is:\n");
	while(head != NULL)
	{
		printf("\n(key = %d, val = %.01f)", head->ListNode_info.key, head->ListNode_info.val);
		head = head->next;
	}
	printf("\n\n");
}

/*Function name: empty_list
Input: Double pointer to head of the tree
Output: None
Algorithm: Recursively releasing allocated memory*/
void empty_list(ListNode **head)
{
	if ((*head) == NULL)
	{
		return;
	}
	empty_list(&((*head)->next));
	free(*head);
	*head = NULL;
}

/*Function name: empty_tree
Input: Double pointer to root of the tree
Output: None
Algorithm: Recursively releasing allocated memory*/
void empty_tree(TreeNode **root)
{
	if (*root == NULL)
	{
		return;
	}
	else
	{
		empty_tree(&((*root)->left));
		empty_tree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

/*Function name: insert_info_by_key
Input: Double pointers to root, root_original and data structure
Output None
Algorithm: Recursively insert data to tree nodes*/
void insert_info_by_key(TreeNode **root, TreeNode **root_original, Data data)
{
	static int times;
	if (!(*root))
	{
		*root = create_tree_node(data);
		if(times == 0)
		{
			*root_original = *root;
				if(*root == NULL)
				{
					printf("Allocation tree node failed");
					empty_tree(root_original);
					exit(1);
				}
		}
	}
	else
	{
		(data.key < (*root)->TreeNode_info.key) ? insert_info_by_key (&((*root)->left), root_original, data) : insert_info_by_key (&((*root)->right), root_original, data);
	}
	times++;
}

/* Function name: treeHight
Input: Pointer to node of the tree
Output: Integer number represents tree hight
Algorithm: Recursively summarize it's hight*/
int treeHight(TreeNode *tree)
{
	int a, b;
	if (tree == NULL)
	{
		return -1;
	}
	else
	{
		a = (1 + treeHight(tree->left));
		b = (1 + treeHight(tree->right));
		return Max(a, b);
	}
}

/* Function name: sum_tree
Input: Pointer to node of the tree
Output: Floating point number represents summation of the node's value
Algorithm: Recursively summarize tree's nodes*/
float sum_tree(TreeNode *tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	return tree->TreeNode_info.val + sum_tree(tree->left) + sum_tree(tree->right);
}

/* Function name: create_search_tree
Input: None
Output: Pointer to tree
Algorithm: For any yes answer, creating a new node and inseting values to it*/
TreeNode *create_search_tree()
{
	Data infoNode;
	char in_char;
	TreeNode *tree = NULL;
	do
	{
		rewind(stdin);
		printf("\nDo you want to enter another node? (y/n): ");
		in_char = getchar();
		if (in_char == 'y')
		{
			printf("\nEnter key and value: ");
			scanf("%d %f", &(infoNode.key), &(infoNode.val));
			insert_info_by_key(&tree, &tree, infoNode);
		}
	}
	while (in_char == 'y');
	return tree;
}

/* Function name: create_tree_node
Input: Data structure
Output: Tree pointer
Algorithm: Creating a node by allocate memory*/
TreeNode *create_tree_node(Data data)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	if (temp != NULL)
	{
		temp->TreeNode_info = data;
		temp->left = NULL;
		temp->right = NULL;
	}
	return temp;
}

/* Function name: create_list_node
Input: Data structure
Output: Pointer to the new node
Algorithm: Allocate memory for the new node and inserting it's data*/
ListNode *create_list_node(Data data)
{
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
	{
		return NULL;
	}
	else
	{
		new_node->ListNode_info = data;
		new_node->next = NULL;
		return new_node;
	}
}

/* Function name: append_lists
Input: Two lists
Output: Pointer to combined list
Algorithm: Running with while loop on the first list untill it reach it's last node and than adds second list as node's next pointer*/
ListNode *append_lists(ListNode *firstList, ListNode *secondList)
{
	ListNode *res;
	res = secondList;
	if (firstList)
	{
		res = firstList;
		while (firstList->next)
		{
			firstList = firstList->next;
		}
		firstList->next = secondList;
	}
	return res;
}

/* Function name: tree_to_inorder_list
Input: Pointer to root of a tree
Output: Pointer to left node
Algorithm: Recursively ordering the tree*/
ListNode *tree_to_inorder_list(TreeNode *root)
{
	ListNode *curr = NULL, *left = NULL, *right = NULL;
	if (root)
	{
		left = tree_to_inorder_list(root->left);
		right = tree_to_inorder_list(root->right);
		curr = create_list_node(root->TreeNode_info);
		curr->next = right;
		left = append_lists(left, curr);
	 }
	return left;
}

/* Function name: tree_to_preorder_list
Input: Pointer to root of a tree
Output: Pointer to left node
Algorithm: Recursively ordering the tree*/
ListNode *tree_to_preorder_list(TreeNode *root)
{
	ListNode* curr = NULL, * right = NULL, * left = NULL;
	if (root != NULL)
	{
		left = tree_to_preorder_list(root->left);
		right = tree_to_preorder_list(root->right);
		curr = create_list_node(root->TreeNode_info);
		curr->next = left;
		left = append_lists(curr, right);
	}
	return left;
}
