#include <stdio.h>


int main(void)
{
    int height, width;
    scanf("%d %d", &height, &width);

    int numberToAdd = (width > 1) + (height > 1);

    printf("%d ", 0 + numberToAdd);
    numberToAdd = height > 1;
    for (int j = 1; j < width - 1; j++)
    {
        printf("%d ", 2 + numberToAdd);
    }
    if (width > 1)
    {
        printf("%d", 1 + numberToAdd);
    }
    printf("\n");

    numberToAdd = width > 1;
    for (int i = 1; i < height - 1; i++)
    {
        printf("%d ", 2 + numberToAdd);
        for (int j = 1; j < width - 1; j++)
        {
            printf("4 ");
        }
        if (width > 1)
        {
            printf("3 ");
        }
        printf("\n");
    }

    if (height > 1)
    {
        printf("%d ", 1 + numberToAdd);
        for (int j = 1; j < width - 1; j++)
        {
            printf("3 ");
        }
        if (width > 1)
        {
            printf("2 ");
        }
    }
    return 0;
}
