#include <stdio.h>
#include <conio.h>

main()
{
	int num1=18, num2=24, num3;
	
	printf("Before Swap\n\n");
	printf("num1 = %d , adress = %d\n", num1, &num1);
	printf("num2 = %d , adress = %d\n\n", num2, &num2);
	
	num3 = num1;
	num1 = num2;
	num2 = num3;
	
	printf("After Swap\n\n");
	printf("num1 = %d , adress = %d\n", num1, &num1);
	printf("num2 = %d , adress = %d", num2, &num2);
	
	getch();
}
