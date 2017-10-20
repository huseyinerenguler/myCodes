#include <stdio.h>
#include <ctype.h>

int main() {
	
	char ch;
	
	printf("Enter a character: ");
	scanf(" %c", &ch);
	
	if (islower(ch))
		printf("IT IS A LOWERCASE LETTER");
	else if (isupper(ch))
		printf("IT IS A UPPERCASE LETTER");
	else
		printf("IT IS NOT A LETTER");
		
	return 0;
}
