#include <stdio.h>
#include <conio.h>

main ()
{
	int factorial;
	int result = 1;
	int factorial2;
	
	printf("Enter the number that you want to calculate: ");
	scanf("%d", &factorial);
	
	factorial2 = factorial;
	
	while (factorial != 0)
	{
		result = result * factorial;
		factorial --;
	}
	
	printf("%d\! = %d", factorial2, result);
	
	getch();
}
