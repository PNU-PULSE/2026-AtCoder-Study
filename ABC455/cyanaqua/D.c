#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
    struct Node* prev;
};

int main(void)
{
    int numberOfCards, numberOfQueries;
    scanf("%d %d", &numberOfCards, &numberOfQueries);

    struct Node* cards = (struct Node*)malloc((numberOfCards + 1) * sizeof(struct Node));

    struct Node* stacks = (struct Node*)malloc((numberOfCards + 1) * sizeof(struct Node));

    for(int i = 1; i <= numberOfCards; i++)
    {
        stacks[i].value = 0;
        stacks[i].next = &cards[i];
        stacks[i].prev = NULL;

        cards[i].value = i;
        cards[i].next = NULL;
        cards[i].prev = &stacks[i];
    }

    for(int i = 0; i < numberOfQueries; i++)
    {
        int source, destination;
        scanf("%d %d", &source, &destination);

        cards[source].prev->next = NULL;
        cards[source].prev = &cards[destination];
        cards[destination].next = &cards[source];
    }

    for(int i = 1; i <= numberOfCards; i++)
    {
        int cardsInStack;
        struct Node* stackIterator = stacks[i].next;
        for(cardsInStack = 0; stackIterator != NULL; cardsInStack++) stackIterator = stackIterator->next;
        printf("%d ", cardsInStack);
    }
    return 0;
}
