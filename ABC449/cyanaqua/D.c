#include <stdio.h>

long long int determineAmountOfPointsBetween(long long int pointBound, long long int negBound, long long int posBound);
long long int max(long long int a, long long int b);
long long int min(long long int a, long long int b);
long long int absLongLongInt(long long int a);

int main(void)
{
    long long int leftBound, rightBound, lowerBound, upperBound;
    long long int numberOfBlackPoints = 0;
    scanf("%lld %lld %lld %lld", &leftBound, &rightBound, &lowerBound, &upperBound);

    for(long long int i = leftBound; i <= rightBound; i++)
    {
        if(absLongLongInt(i) % 2 == 1) continue;
        numberOfBlackPoints += determineAmountOfPointsBetween(absLongLongInt(i), lowerBound, upperBound);
        //prlong long intf("%d black polong long ints at x=%d\n", determineAmountOfPolong long intsBetween(abs(i), lowerBound, upperBound), i);
    }
    for(long long int i = lowerBound; i <= upperBound; i++)
    {
        if(absLongLongInt(i) % 2 == 1 || i == 0) continue;
        numberOfBlackPoints += determineAmountOfPointsBetween(absLongLongInt(i) - 1, leftBound, rightBound);
        //prlong long intf("%d black polong long ints at y=%d\n", determineAmountOfPolong long intsBetween(abs(i) - 1, leftBound, rightBound), i);
    }
    printf("%lld", numberOfBlackPoints);
}

long long int determineAmountOfPointsBetween(long long int pointBound, long long int negBound, long long int posBound)
{
    if(negBound > pointBound) return 0;
    if(posBound < -pointBound) return 0;
    return (min(posBound, pointBound) - max(-pointBound, negBound) + 1);
}

long long int max(long long int a, long long int b)
{
    if(a > b) return a;
    return b;
}

long long int min(long long int a, long long int b)
{
    if(a < b) return a;
    return b;
}

long long int absLongLongInt(long long int a)
{
    if(a >= 0) return a;
    return -a;
}
