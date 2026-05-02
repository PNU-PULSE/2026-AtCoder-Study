#include <stdio.h>

int main(void)
{
    int die[3][6];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            scanf("%d", &die[i][j]);
        }
    }

    int count[7] = {0};

    int totalCases = 6 * 6 * 6;
    int targetCases = 0;

    for(int i = 0; i < 6; i++)
    {
        count[die[0][i]]++;

        for(int j = 0; j < 6; j++)
        {
            count[die[1][j]]++;
            for(int k = 0; k < 6; k++)
            {
                count[die[2][k]]++;
                if((count[4] == 1) && (count[5] == 1) && (count[6] == 1))
                {
                    targetCases++;
                }
                count[die[2][k]]--;
            }
            count[die[1][j]]--;
        }

        count[die[0][i]]--;
    }

    printf("%lf", (double)targetCases / totalCases);
}
