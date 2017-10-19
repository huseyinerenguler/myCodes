#include <stdio.h>

int main() {
	int week, hour;
	char lectureType;

	printf("Enter the number of week in a semester: ");
	scanf_s("%d", &week);

	printf("Enter the number of lecture hour in a week: ");
	scanf_s("%d", &hour);

	printf("What is your lecture (E: for English) / (O: for Others): ");
	scanf_s(" %c", &lectureType);

	if (lectureType == 'E' || lectureType == 'e')
		printf("You must attend %.0lf hours\n", (week*hour)*0.90);
	else if (lectureType == 'O' || lectureType == 'o')
		printf("You must attend %.0lf hours\n", (week*hour)*0.75);
	else
		printf("You entered a wrong lecture code!!!\n");

	return 0;
}