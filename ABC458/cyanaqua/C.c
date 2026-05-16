#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[500010];
    scanf("%s", str);
    long long int count = 0;

    int len = strlen(str);
    int pastHalfway = 0;
    for(int i = 0; i < len; i++)
    {
        if (i >= len / 2) pastHalfway = 1;
        if (str[i] == 'C')
        {
            if(pastHalfway)
            {
                count += len - i;
            }
            else
            {
                count += i + 1;
            }
        }
    }

    printf("%lld", count);
    return 0;
}
