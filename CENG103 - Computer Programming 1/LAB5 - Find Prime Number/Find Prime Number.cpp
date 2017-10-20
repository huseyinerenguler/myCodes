#include <stdio.h>

bool isTriangular(int);
bool isPrime(int);

int main() {

	while(1) {
			printf("      MENU\n");
	printf("---------------\n");
	printf("1. Triangular?\n");
	printf("2. Prime?\n");
	printf("3. EXIT\n\n");
	
	int choice;
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	while (choice != 1 && choice != 2 && choice != 3) {	
		
		printf("Wrong choice! Enter your choice again: ");
		scanf("%d", &choice);
	}
	
	int number;	
	printf("Enter a number: ");
	scanf("%d", &number);
	
	if (choice == 3)
		return 0;
		
	else if (choice == 1) {
		
		if (isTriangular(number))
			printf("%d is a triangular number..\n\n\n", number);
		else
			printf("%d is NOT a triangular number..\n\n\n", number);
	}
	
	else if (choice == 2) {
		
		if (isPrime(number))
			printf("%d is a prime number..\n\n\n", number);
		else
			printf("%d is NOT a prime number..\n\n\n", number);
	}
	
	}
	
	
	return 0;
}

bool isTriangular(int number) {
	
	int result;
	
	for (int x = 1; ; x++) {
		
		result += x;
		
		if (result > number)
			return false;
		else if (result == number)
			return true;	
	}
	
}

bool isPrime(int number) {
	
	bool control = true;
	
	for (int x = 2; x < number; x++) {
		
		if (number % x == 0) {
			control = false;
		}
	}
	
	return control;
}
