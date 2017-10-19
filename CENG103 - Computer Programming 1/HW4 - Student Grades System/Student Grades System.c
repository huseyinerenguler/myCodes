#include <stdio.h>
#define SIZE 10 // size of array

float getAverage (int Grades[]); // function protoype
int getLowest (int Grades[]); // function protoype
int getHighest (int Grades[]); // function protoype
void showDistribution (int Grades[]); // function protoype

main ()
{
	int Grades[SIZE]; // define an array of size 10
	
	printf("The grades are:\n\n"); // prompt for input
	
	for (int x = 0; x < SIZE; x++) // loop for to get values
	{
		while (1) // loop while always run 
		{
			printf("Student %d: ", x+1); // prompt for input
			scanf("%d", &Grades[x]); // read Grades from user
		
			if (Grades[x] < 0 || Grades[x] > 100) // if Grades is less than zero or more than a hundred
				printf("Please enter a valid number between 0 and 100.\n"); // display error
			else
				break;
		}
	}
	
	printf("----------------------");
	printf("\nClass average is %.2f\n", getAverage(Grades)); // call function and print average
	printf("Lowest grade is %d\n", getLowest(Grades)); // call function and print lowest grade
	printf("Highest grade is %d\n", getHighest(Grades)); // call function and print highest grade
	printf("----------------------\n");
	printf("Grade Distribution:\n\n"); showDistribution(Grades); // call function and print disribution
}

float getAverage (int Grades[]) // the function calculates average and returns
{
	int total = 0; // initialize variable that name is total
	
	for (int x = 0; x < SIZE; x++) // loop for to add Grades to total
	{
		total = total + Grades[x]; // add Grades to total
	}
	
	float average = (float) total / SIZE ; // calculate average
	
	return average; // return the average of array
}

int getLowest (int Grades[]) // the function calculates lowest grade and returns
{
	int lowest = Grades[0]; // initialize variable that name is lowest
	
	for (int x = 1; x < SIZE; x++) // loop for find lowest grade 
	{
		if (lowest > Grades[x]) // if lowest is more than Grades
		{
			lowest = Grades[x]; // lowest is equal to Grades
		}
	}
	
	return lowest; // return the lowest grade of array
}

int getHighest (int Grades[]) // the function calculates highest grade and returns
{
	int highest = Grades[0]; // initialize variable that name is highest
	
	for (int x = 1; x < SIZE; x++) // loop for find lowest grade
	{
		if (highest < Grades[x]) // if highest is less than Grades
		{
			highest = Grades[x]; // highest is equal to Grades
		}
	}
	
	return highest; // return the highest grade of array
}

void showDistribution (int Grades[]) // the function show distribution
{
	int flag[11] = {0}; // initialize array that name is flag
	
	for (int x = 0; x < SIZE; x++) // loop for to find ranges
	{
		if (Grades[x] >= 0 && Grades[x] < 10) // if Grades is between zero and ten (without ten)
			flag[0]++; // increment flag[0]
		else if (Grades[x] >= 10 && Grades[x] < 20) // else if Grades is between ten and twenty (without twenty) 
			flag[1]++; // increment flag[1]
		else if (Grades[x] >= 20 && Grades[x] < 30) // else if Grades is between twenty and thirty (without thirty)
			flag[2]++; // increment flag[2]
		else if (Grades[x] >= 30 && Grades[x] < 40) // else if Grades is between thirty and fourty (without fourty)
			flag[3]++; // increment flag[3]
		else if (Grades[x] >= 40 && Grades[x] < 50) // else if Grades is between fourty and fifty (without fifty)
			flag[4]++; // increment flag[4]
		else if (Grades[x] >= 50 && Grades[x] < 60) // else if Grades is between fifty and sixty (without sixty)
			flag[5]++; // increment flag[5]
		else if (Grades[x] >= 60 && Grades[x] < 70) // else if Grades is between sixty and seventy (without seventy)
			flag[6]++; // increment flag[6]
		else if (Grades[x] >= 70 && Grades[x] < 80) // else if Grades is between seventy and eighty (without eighty)
			flag[7]++; // increment flag[7]
		else if (Grades[x] >= 80 && Grades[x] < 90) // else if Grades is between eighty and ninety (without ninety)
			flag[8]++; // increment flag[8]
		else if (Grades[x] >= 90 && Grades[x] < 100) // else if Grades is between ninety and a hundred (without a hundred)
			flag[9]++; // increment flag[9]
		else if (Grades[x] == 100) // else if Grades is equal to a hundred
			flag[10]++; // increment flag[10]
	}
	
	for (int x = 0; x < 11; x++) // loop for show distribution
	{
		if (x == 10)								//
			printf("%5d: ", x*10);					// print
		else										// ranges
			printf("%.2d-%.2d: ", x*10, x*10+9);	//
		
		for (int y = 0; y < flag[x]; y++) // loop for print * according to the flag[] variable
		{
			printf("%c", '*'); // print *
		}
		
		printf("\n");
	}
}
