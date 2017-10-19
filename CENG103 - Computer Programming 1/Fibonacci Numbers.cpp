#include <stdio.h>
#include <conio.h>

main ()
{
	int limit;
	int result;
	int Num1 = 0;
	int Num2 = 1;
	
	printf("Enter the limit: ");
	scanf("%d", &limit);
	
	printf("Fibonacci Numbers: ");
	
	while (result <= limit)
	{
		printf("%d ", Num1);
		
		result = Num1 + Num2;
		Num1 = Num2;
		Num2 = result;
	}
	
	getch();
}
