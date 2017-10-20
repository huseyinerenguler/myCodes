#include <stdio.h>

int Sum_Numbers (int limit);

main ()
{
	int limit;
	
	printf("\tWELCOME !!!\n");
	printf("Recursive Sum of Numbers\n");
	printf("Enter a positive integer: ");
	scanf("%d", &limit);	
	
	printf("\nResult: %d", Sum_Numbers(limit));
}

int Sum_Numbers (int limit)
{
	if (limit == 1)
		return 1;
	else		
		return limit + Sum_Numbers(limit-1);
}
