#include <stdio.h>

int main(void)
{
    int gosekku[5][2] = {{1, 7}, {3, 3}, {5, 5}, {7, 7}, {9, 9} };
    int month, day;
    scanf("%d %d", &month, &day);

    int isGosekku = 0;
    for(int i = 0; i < 5; i++)
    {
        if(month == gosekku[i][0] && day == gosekku[i][1])
        {
            isGosekku = 1;
            break;
        }
    }

    printf("%s", isGosekku? "Yes" : "No");
    return 0;
}
