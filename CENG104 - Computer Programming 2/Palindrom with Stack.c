#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char value);
int pop(StackNodePtr *topPtr);

int main ()
{
	StackNodePtr stackPtr = NULL;

	char myArray[40];
	char reverseArray[40];
	int x, y;
	printf("Enter your word: "); scanf("%s", myArray);

	for (x = 0; myArray[x] != '\0'; x++)
	{
		push(&stackPtr, myArray[x]);
	}
	for (y = 0; y < x; y++)
	{
		reverseArray[y] = pop(&stackPtr);
	}

	if (strcmp(myArray,reverseArray) == 0)
		printf("\nExcellent, your word is PALINDROM! :)\n");
	else
		printf("\nUnfortunately, your word is not a palindrom :(\n");

	return 0;
}

void push(StackNodePtr *topPtr, char value)
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
