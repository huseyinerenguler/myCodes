#include <stdio.h>

int main() {
	int age;
	char disability;
	double baggageWeight;
	double extraBaggage;

	double ticketPayment = 89.99;
	double currentTicketPayment;
	double ticketBaggage = 0.00;
	double baggageLimit = 15.00;

	printf("Enter your age: ");
	scanf_s("%d", &age);

	printf("Disability ? (y/n): ");
	scanf_s(" %c", &disability);

	if (disability == 'Y' || disability == 'y') {
		currentTicketPayment = ticketPayment * 0.60;

		printf("Enter baggage weight: ");
		scanf_s("%lf", &baggageWeight);
		if (baggageWeight > 15) {
			extraBaggage = baggageWeight - baggageLimit;
			ticketBaggage = extraBaggage * 6;

			printf("Your baggage weight exceeds the limit "
				"with %.2lf kg, Please pay %.2lf TL\n\n", extraBaggage, ticketBaggage);
		}

		printf("Ticket Payment: %.2lf TL\n", currentTicketPayment);
		printf("Extra Payment for Baggage: %.2lf TL\n", ticketBaggage);
		printf("Total Payment: %.2lf TL\n", currentTicketPayment + ticketBaggage);
	}

	else if (disability == 'N' || disability == 'n') {
		if (age > 65)
			currentTicketPayment = ticketPayment * 0.85;
		else if (age < 13)
			currentTicketPayment = ticketPayment * 0.67;
		else
			currentTicketPayment = ticketPayment;

		printf("Enter baggage weight: ");
		scanf_s("%lf", &baggageWeight);
		if (baggageWeight > 15) {
			extraBaggage = baggageWeight - baggageLimit;
			ticketBaggage = extraBaggage * 6;

			extraBaggage = baggageWeight - baggageLimit;
			printf("Your baggage weight exceeds the limit "
				"with %.2lf kg, Please pay %.2lf TL\n\n", extraBaggage, extraBaggage * 6);
		}

		printf("Ticket Payment: %.2lf TL\n", currentTicketPayment);
		printf("Extra Payment for Baggage: %.2lf TL\n", ticketBaggage);
		printf("Total Payment: %.2lf TL\n", currentTicketPayment + ticketBaggage);
	}

	else
		printf("Invalid Answer !\n\n");

	return 0;
}