#include <stdio.h>

int main() {
	
	double number;
	
	printf("Enter a number (2 digits integer and 5 digits fractional): ");
	scanf("%lf", &number);
	
	printf("%.5lf\n", number);
	printf("%8.2lf\n", number);
	printf("%.0lf\n", number);
	printf("%.7lf\n", number);
	printf("%15.3lf\n", number);
	printf("%12.8lf\n", number);
	printf("%7.2lf\n", number);
	printf("%6.0lf\n", number);
	printf("%9.1lf\n", number);
	printf("%12.7lf\n", number);
	
	return 0;
}
