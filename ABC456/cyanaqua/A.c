#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int target;
    scanf("%d", &target);

    for(int i = 1; i <= 6; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            for(int k = 1; k <= 6; k++)
            {
                if(i + j + k == target)
                {
                    printf("Yes");
                    exit(0);
                }
            }
        }
    }
    printf("No");
    return 0;
}
