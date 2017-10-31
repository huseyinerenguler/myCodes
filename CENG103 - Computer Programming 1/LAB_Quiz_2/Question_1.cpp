/*
NAME: Hüseyin Eren Güler
ID: 15050111014

-> This program get the ages of "n" number of people and
   display the corresponding messages according to the 
   age of the people.
*/   

#include <stdio.h>

int main() {
	
	// We gets the ages of number of people
	int totalPerson;
	printf("Enter the total person to look: ");
	scanf("%d", &totalPerson);
	
	int age[totalPerson]; // 
	
	
	// loop for gets a age of every person and display messages
	for (int x = 0; x < totalPerson; x++) {
		
		printf("\nEnter the age of %d. person: ", x+1);
		scanf("%d", &age[x]);
		
		// if age is less than zero, print error messages and gets age again
		if (age[x] < 1) {
			printf("You entered wrong value. Enter a number that bigger than zero. \n");
			x--;
			continue;
		}
		
		if (age[x] > 60)				// 60 < age
			printf("Retired\n");	
		else if (age[x] >= 31)			// 31 <= age <= 60
			printf("Middle Aged\n");
		else if (age[x] >= 20)			// 20 <= age <= 30
			printf("Young\n");
		else if (age[x] >= 13)			// 13 <= age <= 19
			printf("Teenager\n");
		else if (age[x] < 13)			// age < 13
			printf("Child\n");
	}
	
	return 0;
}


