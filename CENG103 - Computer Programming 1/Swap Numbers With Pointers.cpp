#include <stdio.h>

void swap_function (int *, int *);

main ()
{
	int number1 = 21;
	int number2 = 87;
	int *num1Ptr, *num2Ptr;
	
	num1Ptr = &number1;
	num2Ptr = &number2;
	
	printf("Before Swap\nNumber1: %d\nNumber2: %d\n", number1, number2);
	swap_function(num1Ptr, num2Ptr);
	printf("\nAfter Swap\nNumber1: %d\nNumber2: %d", number1, number2);
}

void swap_function (int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


