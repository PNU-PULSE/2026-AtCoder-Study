#include <stdio.h>

int main(void)
{
    int costMatrix[105][105];
    int numberOfStations;
    scanf("%d", &numberOfStations);

    for(int i = 1; i <= numberOfStations; i++)
    {
        for(int j = i + 1; j <= numberOfStations; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    int cheaperLongerBoardingFound = 0;

    for(int i = 1; i <= numberOfStations - 2; i ++)
    {
        for(int j = i + 1; j <= numberOfStations - 1; j++)
        {
            for(int k = j + 1; k <= numberOfStations; k++)
            {
                if(costMatrix[i][j] + costMatrix[j][k] < costMatrix[i][k])
                {
                    cheaperLongerBoardingFound = true;
                    goto exitLoop;
                }
            }
        }
    }
    exitLoop:
    printf("%s", cheaperLongerBoardingFound? "Yes" : "No");
    return 0;
}
