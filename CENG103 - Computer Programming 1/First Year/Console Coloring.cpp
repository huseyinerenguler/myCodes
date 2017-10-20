#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

main ()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for (int x = 1; x < 257; x++)
	{
		SetConsoleTextAttribute(hConsole, x-1);
		printf("%d) ", x-1);
		printf("HuseyinKuzeyGuler\t");
		
		if (x % 7 == 0)
			printf("\n");
	}
	
}
