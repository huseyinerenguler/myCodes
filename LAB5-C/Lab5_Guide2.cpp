#include <stdio.h>

int main() {
	
	int amount;
	char county;
	
	printf("Enter the amount of the purchase: ");
	scanf("%d", &amount);
	
	while(1) {
		
		printf("Enter the county: ");
		scanf(" %c", &county);
		
		if (county == 'A' || county == 'B' || county == 'C')
			break;
	}
	
	switch(county) {
		
		case 'A':
			printf("The amount owed is %.2lf", amount*1.07);
			break;
		case 'B':
			printf("The amount owed is %.2lf", amount*1.06);
			break;
		case 'C':
			printf("The amount owed is %.2lf", amount*1.04);
			break;
	}
	
	return 0;
}
