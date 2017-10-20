#include <stdio.h>
#include <conio.h>
#include <math.h>

main ()

{
	float length, area;
	
	printf("Please enter the side length of the square: ");
	scanf("%f", &length);
	
	area = length*length;
	
	printf("\nThe area of square with side length %.2f is %.2f", length, area);
	
	getch();
}
