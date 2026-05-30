#include <stdio.h>

int main(void)
{
    int dividend, divisor, numberOfOperations = 0;
    scanf("%d %d", &dividend, &divisor);

    while(divisor != 0)
    {
        divisor = dividend % divisor;
        numberOfOperations++;
    }
    printf("%d", numberOfOperations);
    return 0;
}
