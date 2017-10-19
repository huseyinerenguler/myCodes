#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);

main ()
{
	StackNodePtr stackPtr = NULL;

	int myArray[10] = {1,2,3,4,5,6,7,8,9,10};
	int reverseArray[10];
	int x;
	printf("Array: ");
	for(x = 0; x < 10; x++)
	{
		printf("%d ", myArray[x]);
	}
	for (x = 0; x < 10; x++)
	{
		push(&stackPtr, myArray[x]);
	}
	for (x = 0; x < 10; x++)
	{
		reverseArray[x] = pop(&stackPtr);
	}
	printf("\nReversing Array: ");
	for(x = 0; x < 10; x++)
	{
		printf("%d ", reverseArray[x]);
	}
}

void push(StackNodePtr *topPtr, int value)
{
	StackNodePtr newPtr;

	newPtr = malloc(sizeof(StackNode));

	if (newPtr != NULL)
	{
		newPtr->data = value;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else
		printf("No memory available!..");
}

int pop(StackNodePtr *topPtr)
{
	StackNodePtr tempPtr;
	int popValue;

	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);

	return popValue;
}
