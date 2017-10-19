#include <stdio.h>

main ()
{
	int digit; // define variables

	printf("\nEnter the number of digits in your number, -1 to end:\n"); // prompt for input
	printf("(This number can be student number, phone number etc.):\n"); // prompt for input
	printf("\t");
	
	scanf("%d", &digit); // read digit from user
	
	while (digit != -1) // loop while digit is not equal to -1
	{		
		int counter = 0; // initialize counter
		int total = 0; // initialize total
		int value; // value to be added to total
		
		while (counter < digit) // loop while counter is less than or equal to digit 
		{
			if (digit == 8) // if digit equal to 8
				printf("Enter %d. digit of your student number: ", counter); // prompt for input
			
			else if (digit == 10) // if digit equal to 10
				printf("Enter %d. digit of your phone number: ", counter); // prompt for input
				
			else // digit is not equal to 8 or 10, digit is any number
				printf("Enter %d. digit of any number: ", counter); // prompt for input
		
			scanf("%d", &value); // read value from user
			total = total + value; // add value to total
			counter ++; // increment counter
		}
	
		printf("\nTotal of digits: %d", total); // display result
		
		printf("\n\nEnter the number of digits in your number, -1 to end:\n"); // prompt for input
		printf("(This number can be student number, phone number etc.):\n"); // prompt for input
		printf("\t");
	
		scanf("%d", &digit); // read digit from user
	}
	
}

