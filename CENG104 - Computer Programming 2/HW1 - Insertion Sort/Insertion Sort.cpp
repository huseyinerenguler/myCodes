#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100 // size of array

// function prototype
void insertionSort (int *arrayPtr); // this function sorts the array from small to large

main ()
{
	int randomArray[SIZE]; // define an array of size 100
	
	srand(time(NULL));
	for (int x = 0; x < SIZE; x++) // loop for to get random numbers
		randomArray[x] = 1 + (rand() % 100);
	
	printf("Old List: "); // print number list before insertion
	for (int x = 0; x < SIZE; x++) // loop for to print numbers
		printf("%d ", randomArray[x]);
		
	int *arrayPtr = &randomArray[0]; // points to first element of array
	insertionSort (arrayPtr); // call function and send address of first element of array
	
	printf("\n\nNew List: "); // print number list after insertion
	for (int x = 0; x < SIZE; x++) // loop for to print numbers
		printf("%d ", randomArray[x]);
}

void insertionSort (int *arrayPtr) // this function sorts the array from small to large
{
	for (int x = 1; x < SIZE; x++) // loop for to change the current number
	{
		for (int y = x; y > 0; y--) // loop for to decrease the current number
		{
			if (*(arrayPtr+y) < *(arrayPtr+y-1)) // if next number less than current number, we will make swap
			{
				int temp = *(arrayPtr+y);		 //
				*(arrayPtr+y) = *(arrayPtr+y-1); //		S W A P
				*(arrayPtr+y-1) = temp;			 //
			}
		}
	}	
}
