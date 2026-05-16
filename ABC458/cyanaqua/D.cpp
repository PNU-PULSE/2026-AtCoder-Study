#include <queue>
#include <vector>
#include <stdio.h>

void swap_ints(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int numberOfQueries, median;
    std::priority_queue<int, std::vector<int>> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    scanf("%d %d", &median, &numberOfQueries);

    for (int i = 0; i < numberOfQueries; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) swap_ints(&a, &b);

        if (a <= median && b >= median)
        {
            max_heap.push(a);

            min_heap.push(b);
        }
        else if (b <= median)
        {
            max_heap.push(a);
            max_heap.push(b);

            min_heap.push(median);
            median = max_heap.top();
            max_heap.pop();
        }
        else
        {
            min_heap.push(a);
            min_heap.push(b);

            max_heap.push(median);
            median = min_heap.top();
            min_heap.pop();
        }
        printf("%d\n", median);
    }
    return 0;
}
