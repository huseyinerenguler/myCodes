#include <stdio.h>

int checkPrimeNumber (int value);

main ()
{
	int start_value, finish_value;
	
	while (1)
	{
		printf("Enter starting value (>=2): ");
		scanf("%d", &start_value);
		
		if (start_value < 2) continue;
		
		while (1)
		{
			printf("Enter limit value (>= first number): ");
			scanf("%d", &finish_value);
			
			if (finish_value < start_value) continue;
			break;
		}
		break;
	}
	
	printf("Prime numbers between %d and %d are: ", start_value, finish_value);
	
	for (start_value; start_value <= finish_value; start_value++)
	{		
		if (checkPrimeNumber(start_value) == 1)
			printf("%d ", start_value);
	}
	
}

int checkPrimeNumber (int value)
{
	int flag = 0;
	
	for (int x = 2; x < value; x++)
	{
		if (value % x == 0)
		{
			flag++;
			break;
		}	
			
	}
	
	if (flag == 0)
		return 1;
	else
		return 0;
		
}












