#include <stdio.h>

int main(void)
{
    int numberOfPeople, numberOfClothes;
    scanf("%d %d", &numberOfPeople, &numberOfClothes);

    int clothesCount[101] = {0};

    for(int i = 0; i < numberOfPeople; i++)
    {
        int clothesID;
        scanf("%d", &clothesID);
        clothesCount[clothesID]++;
    }

    int duplicateFound = 0;
    int zeroFound = 0;
    for(int i = 1; i <= numberOfClothes; i++)
    {
        if(clothesCount[i] > 1) duplicateFound = 1;
        if(clothesCount[i] == 0) zeroFound = 1;
        if(duplicateFound && zeroFound) break;
    }

    printf("%s\n%s", duplicateFound? "No" : "Yes", zeroFound? "No" : "Yes");
    return 0;
}
