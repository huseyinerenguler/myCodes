#include <stdio.h>
#include <conio.h>

main ()
{
	int productnumber = 0, amount;
	
	double total, result;
	double product1Prize = 2.98;
	double product2Prize = 4.50;
	double product3Prize = 9.98;
	double product4Prize = 4.49;
	double product5Prize = 6.87;
	
	printf("Enter the product number sold for one week (1-2-3-4-5) 0 to quit: ");
	scanf("%d", &productnumber);
		
	do
	{
		printf("Enter the amount that sold for one week: ");
		scanf("%d", &amount);
	
		switch (productnumber)
		{
			case 1:
				total = amount * product1Prize;
				printf("Product 1-> Quantity sold for one week: %.2f\n", total);
				break;
			case 2:
				total = amount * product2Prize;
				printf("Product 2-> Quantity sold for one week: %.2f\n", total);
				break;
			case 3:
				total = amount * product3Prize;
				printf("Product 3-> Quantity sold for one week: %.2f\n", total);
				break;
			case 4:
				total = amount * product4Prize;
				printf("Product 4-> Quantity sold for one week: %.2f\n", total);
				break;
			case 5:
				total = amount * product5Prize;
				printf("Product 5-> Quantity sold for one week: %.2f\n", total);
				break;		
		}
		
		printf("\n");
		result = result + total;
		
		printf("Enter the product number sold for one week (1-2-3-4-5) 0 to quit: ");
		scanf("%d", &productnumber);
		
	} while (productnumber != 0);
	
	printf("\n-> All products retail value: %.3f", result);
	
	getch();
	
}
