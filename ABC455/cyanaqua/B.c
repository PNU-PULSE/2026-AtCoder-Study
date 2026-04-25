#include <stdio.h>

int main(void)
{
    int height, width;
    char grid[15][15];
    scanf("%d %d", &height, &width);
    for(int i = 0; i < height; i++) scanf("%s", grid[i]);

    int symmetricRegionCount = 0;
    for(int outer_i = 0; outer_i < height; outer_i++)
    {
        for(int inner_i = 0; inner_i <= outer_i; inner_i++)
        {
            for(int outer_j = 0; outer_j < width; outer_j++)
            {
                for(int inner_j = 0; inner_j <= outer_j; inner_j++)
                {
                    int asymmetrical = 0;
                    for(int i = inner_i; i <= outer_i; i++)
                    {
                        for(int j = inner_j; j <= outer_j; j++)
                        {
                            if(grid[i][j] != grid[outer_i + inner_i - i][outer_j + inner_j - j])
                            {
                                asymmetrical = 1;
                                break;
                            }
                        }
                        if(asymmetrical) break;
                    }

                    if(!asymmetrical) symmetricRegionCount++;
                }
            }
        }
    }
    printf("%d", symmetricRegionCount);
    return 0;
}
