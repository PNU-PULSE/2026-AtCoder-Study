#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = n; i >= 2; i--)
    {
        printf("%d,", i);

    }
    printf("1");
    return 0;
}
