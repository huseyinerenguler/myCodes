#include <stdio.h>
#include <math.h>

double calculateSeries(double,int);

int main () {
	
	int terms;
	double number;
	
	printf("Please enter the number of terms: ");
	scanf("%d", &terms);	
	
	while(terms <= 0) {
		
		printf("Please re-enter the number of terms: ");
		scanf("%d", &terms);		
	}
	
	printf("Please enter a value for x: ");
	scanf("%lf", &number);
	
	printf("The result is %.2lf ", calculateSeries(number, terms));

	return 0;
}

double calculateSeries(double number, int terms) {
	
	double addedNumber = 0.1;
	int power = 1;
	double result = 0;
	
	for(int x = 1; x < terms + 1; x++) {
		
		if(x % 2 == 1)
			result += pow(number + addedNumber, power) / (2*x);
		else
			result -= pow(number + addedNumber, power) / (2*x);
		
		power += 2;
		addedNumber += 0.1;
	}
	
	return result;
}
