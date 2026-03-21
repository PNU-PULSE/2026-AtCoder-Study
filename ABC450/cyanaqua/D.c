#include <stdio.h>
#include <stdlib.h>

// 끝날 때까지 해결 못함

int compare(const void* a, const void* b);

int mod(int dividend, int divisor);

int main(void)
{
    int numberOfIntegers, baseNumber;
    int numbers[200005];
    scanf("%d %d", &numberOfIntegers, &baseNumber);

    for(int i = 0; i < numberOfIntegers; i++)
    {
        int rawInput;
        scanf("%d", &rawInput);
        numbers[i] = rawInput % baseNumber;
    }

    int minimumDifference = baseNumber;

    qsort(numbers, numberOfIntegers, sizeof(int), compare);
    for(int i = 0; i < numberOfIntegers; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    for(int i = 0; i < numberOfIntegers - 1; i++)
    {
        printf("%d %d\n", (numbers[i + 1] - numbers[i]) % baseNumber, mod(numbers[i] - numbers[i + 1], baseNumber));
        if((numbers[i + 1] - numbers[i]) % baseNumber < minimumDifference) minimumDifference = (numbers[i + 1] - numbers[i]) % baseNumber;
        if(mod(numbers[i] - numbers[i + 1], baseNumber) < minimumDifference) minimumDifference = mod(numbers[i] - numbers[i + 1], baseNumber);
    }

    printf("%d", minimumDifference);
    return 0;
}

int compare(const void* a, const void* b) //taken from cppreference
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int mod(int dividend, int divisor)
{
    while(dividend < 0) dividend += divisor;
    return dividend % divisor;
}

