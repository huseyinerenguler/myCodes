#include <stdio.h>
#include <conio.h>

main ()

{
	float weight, height, BMI;
	
	printf("Please enter your weight: ");
	scanf("%f", &weight);
	
	printf("Now, enter the your height: ");
	scanf("%f", &height);
	
	printf("\n");
	
	BMI = weight / (height * height);
	
	if(BMI <= 20)
	{
		printf("Your BMI is %.3f\n", BMI);
		printf("You are weak!");
	}
	else if(BMI <=  30)
	{
		printf("Your BMI is %.3f\n", BMI);
		printf("You are normal!");
	}
	else if(BMI <= 40)
	{
		printf("Your BMI is %.3f\n", BMI);
		printf("You are fat!");
	}
	else if(BMI > 40)
	{
		printf("Your BMI is %.3f\n", BMI);
		printf("You are risky!");
	}
	getch();
}
