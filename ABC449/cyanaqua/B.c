#include <stdio.h>

int main(void)
{
    int height, width;
    int queries;
    scanf("%d %d %d", &height, &width, &queries);
    for(int i = 0; i < queries; i++)
    {
        int queryType, queryValue;
        scanf("%d %d", &queryType, &queryValue);
        switch(queryType)
        {
        case 1:
            printf("%d\n", queryValue * width);
            height -= queryValue;
            break;
        case 2:
            printf("%d\n", queryValue * height);
            width -= queryValue;
            break;
        default:
            printf("oops");
            return 1;
        }
    }
    return 0;
}
