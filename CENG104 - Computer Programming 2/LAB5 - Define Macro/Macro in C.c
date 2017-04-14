#include <stdio.h>

#define SUM(x,y) (x+y)
#define MINIMUM2(x,y) ((x >= y) ? (y) : (x))
#define PRINT(x) printf("Hello %s\n", #x)

int main ()
{
    int first, second;

    //printf("Enter first number: "); scanf("\n%d", &first);
    //printf("Enter second number: "); scanf("\n%d", &second);

    printf("The sum of %d and %d is: %d\n", first, second, SUM(first,second));
    printf("The minimum is: %d\n\n", MINIMUM2(first,second));

    PRINT(Huso);
    PRINT();
    PRINT(HKG);

    return 0;
}
