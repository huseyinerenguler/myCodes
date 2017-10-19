#include <stdio.h>
#include <math.h>

int main() {
	
	int cost, selling;
	
	printf("Enter the value (amount) of the cost price: ");
	scanf("%d", &cost);
	
	printf("Enter the value (amount) of the selling price: ");
	scanf("%d", &selling);
	
	if(cost < selling)
		printf("The status is: Profit\n");
	else
		printf("The status is: Loss\n");
		
	printf("Output amount: %d", abs(cost-selling));
	
	return 0;
}
