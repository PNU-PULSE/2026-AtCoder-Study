#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b) //taken from cppreference
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main(void)
{
    int numberOfShari, numberOfNeta;
    scanf("%d %d", &numberOfShari, &numberOfNeta);
    int* shari = malloc(sizeof(int) * numberOfShari);
    int* neta = malloc(sizeof(int) * numberOfNeta);

    for (int i = 0; i < numberOfShari; i++) scanf("%d", &shari[i]);
    for (int i = 0; i < numberOfNeta; i++) scanf("%d", &neta[i]);

    qsort(shari, numberOfShari, sizeof(int), compare_ints);
    qsort(neta, numberOfNeta, sizeof(int), compare_ints);

    int shariIterator = 0, numberOfSushi = 0;
    for (int i = 0; i < numberOfNeta; i++)
    {
        while (neta[i] > shari[shariIterator] * 2)
        {
            shariIterator++;
            if (shariIterator >= numberOfShari) goto endloop;
        }
        numberOfSushi++;
        shariIterator++;
        if (shariIterator >= numberOfShari) goto endloop;
    }

    endloop:

    printf("%d", numberOfSushi);
    free(shari);
    free(neta);
    return 0;
}
