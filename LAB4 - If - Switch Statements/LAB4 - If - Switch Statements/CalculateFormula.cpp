#include <stdio.h>
#include <math.h>

double calculateFormula(double, double, double);

int main() {
	double a, b, c;

	printf("Enter a: ");
	scanf_s("%lf", &a);

	printf("Enter b: ");
	scanf_s("%lf", &b);

	printf("Enter c: ");
	scanf_s("%lf", &c);

	if (calculateFormula(a, b, c) != NULL)
		printf("The result is %.4f\n", calculateFormula(a, b, c));
	else
		printf("ERROR! Division by ZERO!\n");

	return 0;
}

double calculateFormula(double a, double b, double c) {
	double x, y;
	if (c != 0) {
		x = fabs(a - b) + powf(a, 5.0 / 7.0) + powf(c, 2.0 / 3.0);
		y = a + (b / c) - sqrtf(fabs(5.0 - 2 * c));
	}
	
	if (y != 0)
		return x / y;
	else
		return NULL;
}