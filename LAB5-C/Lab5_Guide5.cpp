#include <stdio.h>

int main() {
	
	int number;
	printf("Enter a positive number (o to STOP): ");
	scanf("%d", &number);
	
	while(1) {
		
		if (number < 0) {
			
			printf("Sorry! You didn't give a positive number!!!\n\n");
			printf("Enter a positive number (o to STOP): ");
			scanf("%d", &number);
		}
		
		else if (number == 0)
			break;
		
		else {
			
			switch (number % 10) {
			
				case 0:
					printf("ZERO ");
					break;
				case 1:
					printf("ONE ");
					break;
				case 2:
					printf("TWO ");
					break;
				case 3:
					printf("THREE ");
					break;
				case 4:
					printf("FOUR ");
					break;
				case 5:
					printf("FIVE ");
					break;
				case 6:
					printf("SIX ");
					break;
				case 7:
					printf("SEVEN ");
					break;
				case 8:
					printf("EIGHT ");
					break;
				case 9:
					printf("NINE ");
					break;	
			}
		
			number = number / 10;
		}
		
	}
	
	return 0;
}
