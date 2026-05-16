#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[31];
    int crop;
    scanf("%s %d", str, &crop);

    for(int i = crop; i < strlen(str) - crop; i++) printf("%c", str[i]);
    return 0;
}
