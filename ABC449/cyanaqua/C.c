#include <stdio.h>

int main(void)
{
    int stringLength, leftBound, rightBound;
    int lastPosition[26];
    char string[500100];

    int numberOfPairs = 0;

    scanf("%d %d %d", &stringLength, &leftBound, &rightBound);
    scanf("%s", string);

    for(int i = 0; i < 26; i++) lastPosition[i] = -1;

    for(int i = stringLength - 1; i >= 0; i--)
    {
        if(lastPosition[string[i] - 'a'] != -1) continue;
        lastPosition[string[i] - 'a'] = i;
    }

    for(int i = 0; i < stringLength - leftBound; i++)
    {
        for(int j = leftBound; j <= rightBound; j++)
        {
            if(i + j > lastPosition[string[i] - 'a']) break;
            if(i + j >= stringLength) break;

            if(string[i] == string[i + j])
            {
                numberOfPairs++;
            }
        }
    }
    printf("%d", numberOfPairs);
    return 0;
}
