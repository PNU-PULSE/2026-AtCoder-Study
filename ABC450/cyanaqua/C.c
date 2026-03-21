#include <stdio.h>

int height, width;
char grid[2][1005][1005]; // [checked][i][j]

int positionArray[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

int checkForValidComponent(int posRow, int posCol)
{
    grid[1][posRow][posCol] = 1;
    if(posRow == 0 || posRow == height - 1) return 0;
    if(posCol == 0 || posCol == width - 1) return 0;

    int isValidComponent = 1;

    for(int i = 0; i < 4; i++)
    {
        if(grid[0][posRow + positionArray[0][i]][posCol + positionArray[1][i]] == '#') continue;
        if(grid[1][posRow + positionArray[0][i]][posCol + positionArray[1][i]] == 1) continue;
        isValidComponent *= checkForValidComponent(posRow + positionArray[0][i], posCol + positionArray[1][i]);
    }
    return isValidComponent;
}

int main(void)
{
    scanf("%d %d", &height, &width);

    for(int i = 0; i < height; i++)
    {
        scanf("%s", grid[0][i]);
    }

    int numberOfComponents = 0;

    for(int i = 1; i < height - 1; i++)
    {
        for(int j = 1; j < width - 1; j++)
        {
            if(grid[1][i][j] == 1) continue;
            if(grid[0][i][j] == '#') continue;
            numberOfComponents += checkForValidComponent(i, j);
        }
    }
    printf("%d", numberOfComponents);
    return 0;
}
