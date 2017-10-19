#include <stdio.h>

int main() {
	int number1, number2;

	printf("Enter first number: ");
	scanf_s("%d", &number1);

	printf("Enter second number: ");
	scanf_s("%d", &number2);

	printf("The sum of the numbers: %d\n", number1 + number2);
	printf("The difference of the numbers: %d\n", number1 - number2);
	printf("The product of the numbers: %d\n", number1 * number2);

	return 0;
}