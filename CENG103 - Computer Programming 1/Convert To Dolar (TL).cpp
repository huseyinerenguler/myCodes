#include <stdio.h>

void convertToDollar (float TL_1);
void displayResult (float TL_2, float Dollar_1);

main ()
{
	float TL;
	
	printf("Enter the amount of money in Turkish Lira: ");
	scanf("%f", &TL);
	
	convertToDollar(TL);
}

void convertToDollar (float TL_1)
{
	float Dollar = TL_1 / 3.30;
	
	displayResult (TL_1, Dollar);
}

void displayResult (float TL_2, float Dollar_1)
{
	printf("According to 1 TL --> 3.30 $\n\n");
	printf("%.2f TL --> %.2f $\n\n", TL_2, Dollar_1);
	printf("GOOD BYE!");
}
