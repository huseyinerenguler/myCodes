#include <stdio.h>

int main(void) {
	
	// variable declaration
	double num1, num2;
	char ch1, ch2;
	
	printf("Enter two double numbers: ");
	scanf("%lf %lf", &num1, &num2);
	
	printf("Enter two characters: ");
	scanf(" %c %c", &ch1, &ch2);
	
	double avg = (num1+num2) / 2.0;
	
	/* displaying the result */
	printf("Average is: %.2lf\n", avg);
	printf("Two characters are %c %c", ch1, ch2);
	
	return 0;
}
