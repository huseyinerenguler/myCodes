#include <stdio.h>
#include <stdlib.h>

struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
};
typedef struct tnode TreeNode;
typedef TreeNode *TreeNodePtr;

TreeNodePtr rootPtr = NULL;
TreeNodePtr *nodePtr = &rootPtr;

void insert (int data); // this function adds element to the binary tree
void printPreorder (TreeNodePtr rootPtr); // this function shows the number of the tree, according to Preorder Tree Traversal rule
void printPostorder (TreeNodePtr rootPtr); // this function shows the number of the tree, according to Postorder Tree Traversal rule
void printInorder (TreeNodePtr rootPtr); // this function shows the number of the tree, according to Inorder Tree Traversal rule

int main ()
{
	int insertNumber[8] = {3,1,0,2,8,6,5,9};

	int x;
	for (x = 0; x < 8; x++)
		insert (insertNumber[x]);

	printf("Preorder traversal of binary tree is: ");
	printPreorder (rootPtr);

	printf("\n\nPostorder traversal of binary tree is: ");
	printPostorder (rootPtr);

	printf("\n\nInorder traversal of binary tree is: ");
	printInorder (rootPtr);

	return 0;
}

void insert (int data) // this function adds element to the binary tree
{
	if (*nodePtr == NULL) // we find correct place for the element to add to binary tree
	{
		*nodePtr = malloc(sizeof(TreeNode));

		if (*nodePtr != NULL) // successfully created
		{
			(*nodePtr)->data = data;
			(*nodePtr)->left = NULL;
			(*nodePtr)->right = NULL;
		}
		else // no memory
			printf("%d not inserted!\n\n", data);
	}
	else
	{
		if (data < (*nodePtr)->data)
		{
			nodePtr = &((*nodePtr)->left); // we go left subtree
			insert (data);
		}
		else if (data > (*nodePtr)->data)
		{
			nodePtr = &((*nodePtr)->right); // we go right subtree
			insert (data);
		}
		else
			printf("%d is already inserted!\n", data);
	}

	nodePtr = &rootPtr; // we points the address of the first element of the binary tree
}

void printPreorder (TreeNodePtr rootPtr) // this function shows the number of the tree, according to Preorder Tree Traversal rule
{
	if (rootPtr != NULL)
	{
		printf("%d ", rootPtr->data);
		printPreorder(rootPtr->left);
		printPreorder(rootPtr->right);
	}
}

void printPostorder (TreeNodePtr rootPtr) // this function shows the number of the tree, according to Postorder Tree Traversal rule
{
    if (rootPtr != NULL)
    {
		printPostorder(rootPtr->left);
        printPostorder(rootPtr->right);
        printf("%d ", rootPtr->data);
	}
}

void printInorder (TreeNodePtr rootPtr) // this function shows the number of the tree, according to Inorder Tree Traversal rule
{
	if (rootPtr != NULL)
	{
		printInorder(rootPtr->left);
		printf("%d ", rootPtr->data);
		printInorder(rootPtr->right);
	}
}
