#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void adamAsmaca (int user_ID, int maxLevel, int numWin, int playCount); // function prototype
void generateReport (int user_ID, int maxLevel, int numWin, int playCount); // function prototype

main ()
{
	srand(time(NULL)); // randomize random number generator using current time
	
	int maxLevel = 1; // initialize maxLevel
	int numWin = 0; // initialize numWin
	int playCount = 0; // initialize playCount
	int user_ID; // define variable
	
	printf("What is your ID ? : "); // prompt for input
	scanf("%d", &user_ID); // read user_ID from user
		
	while (1) // loop while always run
	{
		int choice; // define variable 
		
		printf("\n\t1. Start Game\n\t2. End Game\n"); // prompt for input
		printf("\tEnter your choice: "); // prompt for input
		scanf("%d", &choice); // read choice from user
		printf("\n");
	
		if (choice == 1) // if choice is equal to one
			adamAsmaca (user_ID, maxLevel, numWin, playCount); // start game
		else if (choice == 2) // if choice is equal to two
		{
			printf("----------GOOD BYE----------\n"); // end game
			break;
		}
	}
}

void adamAsmaca (int user_ID, int maxLevel, int numWin, int playCount) // the function that plays the game with the loop
{
	if (maxLevel == 1) // if maxLevel is equal to one
	{
		printf("----------LEVEL 1----------"); // display level number
		printf("\n***");
		int counter = 7; // initialize counter
		int random = 100 + rand() % 900; // pick random value
				
		int A = random / 100 % 10; // calculate the number of hundreds of the random number
		int B = random / 10 % 10; // calculate the number of tens of the random number
		int C = random / 1 % 10; // calculate the number of ones of the random number
			
		int flagA = 0; // initialize flagA
		int flagB = 0; // initialize flagB
		int flagC = 0; // initialize fiagC
			
		while (counter > 0) // loop while counter is more than zero 
		{ 
			int guess; // define variable
				
			printf("\n(You have %d guesses) Enter your guess: ", counter); // prompt for input
			scanf("%d", &guess); // read guess from user
			
			if (guess < 0 || guess > 9) // if guess is less than zero or more than nine
			{
				printf("\nYour guess must be between 0-9 !"); // display error
				continue;
			}
			
			if (guess == A) // if guess is equal to A
				flagA++; // increment flagA
			if (guess == B) // if guess is equal to B
				flagB++; // increment flagB
			if (guess == C) // if guess is equal to C
				flagC++; // increment flagC
			
			if (flagA > 0) // if flagA is more than zero
				printf("%d", A); // print A
			else
				printf("*"); // print *
			if (flagB > 0) // if flagA is more than zero
				printf("%d", B); // print B
			else
				printf("*"); // print *
			if (flagC > 0) // if flagA is more than zero
				printf("%d", C); // print C
			else
				printf("*"); // print *
				
			counter--; // decrement counter
				
			if (flagA > 0 && flagB > 0 && flagC > 0) // if flagA and flagB and flagC are more than zero 
			{
				printf("\n\tYou win the game!\n\tThe generated number is: %d\n\n", random); // display generated number and user win the game
				
				numWin++; // increment numWin
				playCount++; // increment playCount
				maxLevel = 2; // maxLevel is equal to two
				break;
			}					
		}
		
		if (counter == 0) // if counter is equal to zero
		{
			printf("\n\tYou lost the game!\n\tThe generated number is: %d\n\n", random); // display generated number and user lost the game 
			
			playCount++; // increment playCount
			
			generateReport (user_ID, maxLevel, numWin, playCount); // display report
		}
	}
	
	if (maxLevel == 2) // if maxLevel is equal to two
	{
		printf("----------LEVEL 2----------"); // display level number
		printf("\n****");
		int counter = 6; // initialize counter
		int random = 1000 + rand() % 9000; // pick random value
				
		int A = random / 1000 % 10; // calculate the number of thousands of the random number
		int B = random / 100 % 10; // calculate the number of hundreds of the random number
		int C = random / 10 % 10; // calculate the number of tens of the random number
		int D = random / 1 % 10; // calculate the number of ones of the random number
			
		int flagA = 0; // initialize flagA
		int flagB = 0; // initialize flagB
		int flagC = 0; // initialize flagC
		int flagD = 0; // initialize flagD
			
		while (counter > 0) // loop while counter is more than zero 
		{ 
			int guess; // define variable
				
			printf("\n(You have %d guesses) Enter your guess: ", counter); // prompt for input
			scanf("%d", &guess); // read guess from user
			
			if (guess < 0 || guess > 9) // if guess is less than zero or more than nine
			{
				printf("\nYour guess must be between 0-9 !"); // display error
				continue;
			}
			
			if (guess == A) // if guess is equal to A
				flagA++; // increment flagA
			if (guess == B) // if guess is equal to B
				flagB++; // increment flagB
			if (guess == C) // if guess is equal to C
				flagC++; // increment flagC
			if (guess == D) // if guess is equal to D
				flagD++; // increment flagD
			
			if (flagA > 0) // if flagA is more than zero
				printf("%d", A); // print A
			else
				printf("*"); // print *
			if (flagB > 0) // if flagB is more than zero
				printf("%d", B); // print B
			else
				printf("*"); // print *
			if (flagC > 0) // if flagC is more than zero
				printf("%d", C); // print C
			else
				printf("*"); // print *
			if (flagD > 0) // if flagD is more than zero
				printf("%d", D); // print D
			else
				printf("*"); // print *
				
			counter--; // decrement counter
				
			if (flagA > 0 && flagB > 0 && flagC > 0 && flagD > 0) // if flagA and flagB and flagC and flagD are more than zero
			{
				printf("\n\tYou win the game!\n\tThe generated number is: %d\n\n", random); // display generated number and user win the game
				
				numWin++; // increment numWin
				playCount++; // increment playCount
				maxLevel = 3; // maxLevel is equal to three
				break;
			}				
		}
		
		if (counter == 0) // if counter is equal to zero
		{
			printf("\n\tYou lost the game!\n\tThe generated number is: %d\n\n", random); // display generated number and user lost the game
			
			playCount++; // increment playCount
			
			generateReport (user_ID, maxLevel, numWin, playCount); // display report
		}
	}
	
	if (maxLevel == 3) // if maxLevel is equal to three
	{
		printf("----------LEVEL 3----------"); // display level number
		printf("\n*****");
		int counter = 5; // initialize counter
		int random = 10000 + rand() % 90000; // pick random value
				
		int A = random / 10000 % 10; // calculate the number of tens of thousands of the random number
		int B = random / 1000 % 10; // calculate the number of thousands of the random number
		int C = random / 100 % 10; // calculate the number of hundreds of the random number
		int D = random / 10 % 10; // calculate the number of tens of the random number
		int E = random / 1 % 10; // calculate the number of ones of the random number
			
		int flagA = 0; // initialize flagA
		int flagB = 0; // initialize flagB
		int flagC = 0; // initialize flagC
		int flagD = 0; // initialize flagD
		int flagE = 0; // initialize flagE
			
		while (counter > 0) // loop while counter is more than zero
		{ 
			int guess; // define variable
				
			printf("\n(You have %d guesses) Enter your guess: ", counter); // prompt for input
			scanf("%d", &guess); // read guess from user
			
			if (guess < 0 || guess > 9) // if guess is less than zero or more than nine
			{
				printf("\nYour guess must be between 0-9 !"); // display error
				continue;
			}
			
			if (guess == A) // if guess is equal to A
				flagA++; // increment flagA
			if (guess == B) // if guess is equal to B
				flagB++; // increment flagB
			if (guess == C) // if guess is equal to C
				flagC++; // increment flagC
			if (guess == D) // if guess is equal to D
				flagD++; // increment flagD
			if (guess == E) // if guess is equal to E
				flagE++; // increment flagE
			
			if (flagA > 0) // if flagA is more than zero
				printf("%d", A); // print A
			else
				printf("*"); // print *
			if (flagB > 0) // if flagB is more than zero
				printf("%d", B); // print B
			else
				printf("*"); // print *
			if (flagC > 0) // if flagC is more than zero
				printf("%d", C); // print C
			else
				printf("*"); // print *
			if (flagD > 0) // if flagD is more than zero
				printf("%d", D); // print D
			else
				printf("*"); // print *
			if (flagE > 0) // if flagE is more than zero
				printf("%d", E); // print E
			else
				printf("*"); // print *
		
			counter--; // decrement counter
				
			if (flagA > 0 && flagB > 0 && flagC > 0 && flagD > 0 && flagE > 0) // if flagA and flagB and flagC and flagD and flagE are more than zero
			{
				printf("\n\tYou win the game!\n\tThe generated number is: %d\n\n", random); // display generated number and user win the game
				
				numWin++; // increment numWin
				playCount++; // increment playCount
				maxLevel = 4; // maxLevel is equal to four
				
				generateReport (user_ID, maxLevel, numWin, playCount); // display report
				break;
			}				
		}
		
		if (counter == 0) // if counter is equal to zero
		{
			printf("\n\tYou lost the game!\n\tThe generated number is: %d\n\n", random); // display generated number and user lost the game
			
			playCount++; // increment playCount
			
			generateReport (user_ID, maxLevel, numWin, playCount); // display report
		}
	}
}

void generateReport (int user_ID, int maxLevel, int numWin, int playCount) // the function that display report 
{
	printf("----------REPORT----------\n");
	printf("The user ID is: %d\n", user_ID); // display the ID of the user
	printf("The number of plays is: %d\n", playCount); // display the number of play
	printf("The number of wins is: %d\n", numWin); // display the number of win
	printf("The level is: %d\n", maxLevel); // display the maximum level of the user
}
