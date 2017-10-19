#include <stdio.h>
#include <math.h>

int main() {
	
	int x, y, z;
	
	printf("Enter a value for x: ");
	scanf("%d", &x);
	
	printf("Enter a value for y: ");
	scanf("%d", &y);
	
	printf("Enter a value for z: ");
	scanf("%d", &z);

	double result = abs(pow((pow(x,3.0)/pow(y,4.0/5.0)) + sqrt(abs(x+z) / sqrt(y)),3.0));
	
	printf("The result is %.1lf", result);
}
