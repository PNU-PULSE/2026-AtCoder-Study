#include <stdio.h>

int main(void)
{
    int height, width;
    scanf("%d %d", &height, &width);

    for(int i = 0; i < width; i++) printf("#");
    printf("\n");

    for(int i = 1; i < height - 1; i++)
    {
        printf("#");
        for(int i = 1; i < width - 1; i++) printf(".");
        printf("#\n");
    }

    for(int i = 0; i < width; i++) printf("#");
    return 0;
}
