#include <stdio.h>
#include <string.h>
#define MOD 998244353

long long int getSubstringCountFromLength(int len)
{
    long long int n = len;
    if(len < 0) return 0;
    return n * (n + 1) / 2;
}

int main(void)
{
    char string[300010];
    scanf("%s", string);

    int adjacencyZones[300010][2]; // [i][0]: starting position of zone, [i][1]: end position of zone
    int adjacencyZoneCount = 0;

    int adjacentState = 0; // 0 - false, 1 - true

    for(int i = 0; i < strlen(string); i++)
    {
        switch(adjacentState)
        {
        case 0:
            if(string[i] == string[i + 1])
            {
                adjacentState = 1;
                adjacencyZones[adjacencyZoneCount][0] = i;
            }
            break;

        case 1:
            if(string[i] != string[i + 1])
            {
                adjacencyZones[adjacencyZoneCount][1] = i;
                adjacencyZoneCount++;
                adjacentState = 0;
            }
            break;
        }
    }

    if(adjacencyZoneCount == 0)
    {
        printf("%d", getSubstringCountFromLength(strlen(string)) % MOD);
        return 0;
    }

    int uniqueZoneLengths[300010];

    uniqueZoneLengths[0] = adjacencyZones[0][0] + 1;

    for(int i = 1; i < adjacencyZoneCount; i++)
    {
        uniqueZoneLengths[i] = adjacencyZones[i][0] - adjacencyZones[i - 1][1] + 1;
    }
    uniqueZoneLengths[adjacencyZoneCount] = strlen(string) - adjacencyZones[adjacencyZoneCount - 1][1];

    long long int sumOfSubstrings = 0;
    for(int i = 0; i <= adjacencyZoneCount; i++)
    {
        sumOfSubstrings += getSubstringCountFromLength(uniqueZoneLengths[i]) % MOD;
        sumOfSubstrings %= MOD;
    }

    for(int i = 0; i < adjacencyZoneCount; i++)
    {
        sumOfSubstrings += adjacencyZones[i][1] - adjacencyZones[i][0] - 1;
        sumOfSubstrings %= MOD;
    }
    printf("%lld", sumOfSubstrings);
}
