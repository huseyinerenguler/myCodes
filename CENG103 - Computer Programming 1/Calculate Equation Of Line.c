#include <stdio.h>
#include <conio.h>

main ()

{
	float x1, y1, x2, y2; // coordinate points
	
	printf("..WELCOME TO THE EQUATION OF THE LINE PROGRAM..\n\n"); // display welcome
	printf("Please enter the coordinates of the first point..\n"); // prompt for input
	
	printf("Coordinate X: "); // prompt for input
	scanf("%f", &x1); // read point from user	
	printf("Coordinate Y: "); // prompt for input
	scanf("%f", &y1); // read point from user
	
	printf("\nNice! Now enter the coordinates of the second point..\n"); // prompt for input
	
	printf("Coordinate X: "); // prompt for input 
	scanf("%f", &x2); // read point from user
	printf("Coordinate Y: "); // prompt for input 
	scanf("%f", &y2); // read point from user
		
	float P = y2-y1; // reference point to find the slope
	float T = x2-x1; // reference point to find the slope
	
	if (T != 0)
	{
		float slope = P / T ; // calculate the slope
		float b = y1 - slope*x1 ; // calculate the "b" point on the y=mx+b
	
		printf("\nThe slope of the line: %.2f", slope); // display result

		if (b < 0)
		{
			b = 1-b; // the process for the output look good
			printf("\nThe equation of the line: y = %.2fx - %.2f", slope, b); // display result
		}
		else if (b > 0)
		{
			printf("\nThe equation of the line: y = %.2fx + %.2f", slope, b); // display result
		}
		else
		{
 			printf("\nThe equation of the line: y = %.2fx", slope); // display result
		}	
	}
	else
	{
		printf("\nThe equation of the line: x = %.2f", x1); // display result
	}
	
	printf("\n\nThank You For Choosing Us !\n");
	
	getch();
}
