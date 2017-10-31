/*
NAME: Hüseyin Eren Güler
ID: 15050111014

-> This program calculates the discount amount according to mount, km and car year
   and displays it on the screen.
*/

#include <stdio.h>

void Menu (void); // prints the options on the screen 
void March (char); // prints the discount amount for mount MARCH
void April (char); // prints the discount amount for mount APRIL
void September (char); // prints the discount amount for mount SEPTEMBER

int main() {
	
	char carType; // car type -> Second Hand or New
	int month;
	
	while(1) {
		
		Menu();
		scanf("%d", &month);
		
		if (month == 4) // if user choice 4, program will be exit
			return 0;
		
		printf("New Car (N/n) / Second Hand (S/s): ");
		scanf(" %c", &carType);
		
		switch (month) {
			
			case 1: // user choice 1 -> MARCH
				March(carType);
				break;
				
			case 2: // user choice 1 -> APRIL
				April(carType);
				break;
				
			case 3: // user choice 1 -> SEPTEMBER
				September(carType);
				break;
		}
	}
	
	return 0;
}

// prints the options on the screen 
void Menu (void) {
	
	printf("CAR MANUFACTURER CAMPAIGN MONTHS \n");
	
	printf("1. MARCH \n");
	printf("2. APRIL \n");
	printf("3. SEPTEMBER \n");
	printf("4. EXIT \n");
	
	printf("Select your month to see the sales: ");
}

// prints the discount amount for mount MARCH
void March (char carType) {
	
	int carKm;
	
	printf("Enter the km of your car: ");
	scanf("%d", &carKm);
				
	if ((carType == 's' || carType == 'S') && carKm < 10000) // if car is second hand and km is less than 10000
		printf("You have totally %c%d discount amount for MARCH\n\n", '%', 15);
				
	else if ((carType == 's' || carType == 'S') && carKm > 10000) // if car is second hand and km is bigger than 10000
		printf("You have totally %c%d discount amount for MARCH\n\n", '%', 20);
					
	else
		printf("No discount\n");
}

// prints the discount amount for mount APRIL
void April (char carType) {
	
	if (carType == 'n' || carType == 'N')
		printf("You have totally %c%d discount amount for APRIL\n\n", '%', 5);
				
	else
		printf("No discount\n");	
}

// prints the discount amount for mount SEPTEMBER
void September (char carType) {
	
	int carModel;
	
	printf("Enter the model of yor car: ");
		scanf("%d", &carModel);
				
	if ((carType == 's' || carType == 'S') && carModel < 2015) // if car is second hand and year is less than 2015
		printf("You have totally %c%d discount amount for SEPTEMBER\n\n", '%', 30);
					
	else if ((carType == 's' || carType == 'S') && carModel > 2015) // if car is second hand and year is bigger than 2015
		printf("You have totally %c%d discount amount for SEPTEMBER\n\n", '%', 25);
			
	else
		printf("No discount\n");
}
