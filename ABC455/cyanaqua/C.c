#include <stdio.h>
#include <stdlib.h>

int compare_longlongints(const void* a, const void* b) //taken from cppreference
{
    long long int arg1 = *(const long long int*)a;
    long long int arg2 = *(const long long int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main(void)
{
    long long int sequenceLength, sequence[300010], numberOfOperations;
    scanf("%lld %lld", &sequenceLength, &numberOfOperations);

    for(int i = 0; i < sequenceLength; i++)
    {
        scanf("%lld", &sequence[i]);
    }

    qsort(sequence, sequenceLength, sizeof(long long), compare_longlongints);

    long long int compareValue = sequence[0];
    long long int sumsOfEqualElements[300010] = {0}, sumCount = 0;

    for(long long int i = 0; i < sequenceLength; i++)
    {
        if(sequence[i] != compareValue)
        {
            compareValue = sequence[i];
            sumCount++;
        }
        sumsOfEqualElements[sumCount] += sequence[i];
    }
    sumCount++;

    qsort(sumsOfEqualElements, sumCount, sizeof(long long), compare_longlongints);

    long long int minimumSum = 0;

    for(int i = 0; i < sumCount - numberOfOperations; i++) minimumSum += sumsOfEqualElements[i];

    printf("%lld", minimumSum);
    return 0;
}
