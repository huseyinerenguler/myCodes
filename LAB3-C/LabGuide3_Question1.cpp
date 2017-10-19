#include <stdio.h>

int main() {
	
	int num1, num2;
	
	printf("Enter first number: ");
	scanf("%d", &num1);
	
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	printf("The sum of the numbers: %d\n", num1+num2);
	printf("The difference of the numbers: %d\n", num1-num2);
	printf("The product of the numbers: %d\n", num1*num2);
	
	return 0;
}
