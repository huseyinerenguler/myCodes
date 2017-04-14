#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node *nextPtr;
};

typedef struct node Node;
typedef Node *NodePtr;

void instructions (void);
void insert (NodePtr *sPtr, char value);

main ()
{
	NodePtr startPtr = NULL;
	int choice;
	char item;

	instructions();
	printf("? "); scanf("%d", &choice);

	while (choice != 3)
	{
		switch (choice)
		{
			case 1:
				printf("Enter a character: ");
				scanf("%c", &item);
				insert(&startPtr, item);
				break;
		}
	}
}

void instructions (void)
{
	printf("Enter your choice:\n");
	printf("1 -> INSERT\n2 -> DELETE\n3 -> EXIT\n");
}

void insert (NodePtr *sPtr, char value)
{
	NodePtr newPtr;
	NodePtr previousPtr;
	NodePtr currentPtr;

	newPtr = malloc(sizeof(Node));

	if (newPtr != NULL) // memory is available
	{
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->data)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}

		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}

	else
	{
	printf("No memory available.\n");
	}
}
