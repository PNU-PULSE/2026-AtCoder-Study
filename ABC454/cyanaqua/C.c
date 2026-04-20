#include <stdio.h>
#include <stdlib.h>

struct NodeLinkedList
{
    int value;
    struct NodeLinkedList* next;
};

struct NodeGraph
{
    int value;
    int searched;
    struct NodeLinkedList* adjacentHead;
};

void insert(struct NodeLinkedList** node, int value)
{
    if(*node != NULL)
    {
        struct NodeLinkedList* newNode = (struct NodeLinkedList*)malloc(sizeof(struct NodeLinkedList));
        newNode->value = value;
        newNode->next = (*node)->next;
        (*node)->next = newNode;
    }
    else
    {
        struct NodeLinkedList* newNode = (struct NodeLinkedList*)malloc(sizeof(struct NodeLinkedList));
        newNode->value = value;
        newNode->next = NULL;
        *node = newNode;
    }
}

int main(void)
{
    int numberOfItems, numberOfFriends;
    struct NodeGraph* itemNetwork[300010] = {0};

    scanf("%d %d", &numberOfItems, &numberOfFriends);

    for(int i = 1; i <= numberOfItems; i++)
    {
        itemNetwork[i] = (struct NodeGraph*)malloc(sizeof(struct NodeGraph));
        itemNetwork[i]->value = i;
        itemNetwork[i]->searched = 0;
        itemNetwork[i]->adjacentHead = NULL;
    }

    for(int i = 0; i < numberOfFriends; i++)
    {
        int want, offer;
        scanf("%d %d", &want, &offer);
        insert(&(itemNetwork[want]->adjacentHead), offer);
    }

    int searchStack[300010] = {1}, stackSize = 1;

    int currentIndex, numberOfItemsObtainable = 0;

    do
    {
        if(stackSize > 0) currentIndex = searchStack[--stackSize];
        itemNetwork[currentIndex]->searched = 1;
        numberOfItemsObtainable++;

        struct NodeLinkedList* iterator = itemNetwork[currentIndex]->adjacentHead;
        while(iterator != NULL)
        {
            if(!itemNetwork[iterator->value]->searched)
            {
                itemNetwork[iterator->value]->searched = 1;
                searchStack[stackSize++] = iterator->value;
            }
            iterator = iterator->next;
        }

    }while(stackSize > 0);

    printf("%d\n", numberOfItemsObtainable);

    return 0;
}
