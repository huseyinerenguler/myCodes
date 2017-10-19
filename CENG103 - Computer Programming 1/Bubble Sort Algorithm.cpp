#include <stdio.h>
#define SIZE 9

float Average (int List[]);
int Mode (int List[]);

main ()
{
	int List[SIZE] = {16, 18, 14, 14, 13, 16, 14, 21, 13};
	int temp;
	
	for (int x = 0; x < SIZE; x++)
	{
		printf("%d ", List[x]);
	}
	
	for (int x = 0; x < SIZE - 1; x++)
	{
		for (int x = 0; x < SIZE - 1; x++)
		{
			if (List[x] > List[x+1])
			{
				temp = List[x];
				List[x] = List[x+1];
				List[x+1] = temp;
			}
		}
	}
	
	printf("\n");
	
	for (int x = 0; x < SIZE; x++)
	{
		printf("%d ", List[x]);
	}
	
	printf("\n\nAverage is: %.2f", Average(List));
	printf("\nMedian is: %d", List[SIZE / 2]);
	printf("\nMode is: %d", Mode(List));
	
}

float Average (int List[])
{
	int total = 0;
	
	for (int x = 0; x < SIZE; x++)
	{
		total = total + List[x];
	}
	
	float average = (float) total / SIZE;
	
	return average;
}

int Mode (int List[])
{
	int number = 0, max_number = 0;
	int count = 1, max_count = 1;
	
	for (int x = 0; x < SIZE - 1; x++)
	{
		if (List[x] == List[x+1])
		{
			number = List[x];
			count++;
		}
		else
		{
			if (count > max_count)
			{
				max_number = List[x];
				max_count = count;
				count = 1;
			}
		}
	}
	
	return max_number;
}
