#include <stdio.h>
#include <math.h>

typedef long long int lint;
typedef struct Point2
{
    lint x;
    lint y;
} Point2;

lint sqr(lint a) { return a * a; }

lint distanceSquared(Point2 a, Point2 b)
{
    return sqr(b.x - a.x) + sqr(b.y - a.y);
}

lint diff(lint a, lint b)
{
    if (a > b) return a - b;
    return b - a;
}

int main(void)
{
    int numberOfTestCases;
    scanf("%d", &numberOfTestCases);

    for(int i = 0; i < numberOfTestCases; i++)
    {
        Point2 center1, center2;
        lint radius1, radius2;

        scanf("%lld %lld %lld %lld %lld %lld", &(center1.x), &(center1.y), &radius1, &(center2.x), &(center2.y), &radius2);

        if ((distanceSquared(center1, center2) <= sqr(radius1 + radius2)) && (distanceSquared(center1, center2) >= sqr(diff(radius1, radius2)))) printf("Yes\n");

        else printf("No\n");
    }
    return 0;
}
