#include<stdio.h>
#include<stdlib.h>

typedef struct dll
{
    int data;
    struct dll *next;
}node;

node *end(int num)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->next = NULL;

    return new;
}

void loopdetect(node **head)
{
    int x=0,y=0;
    node *temp1 = *head;
    node *temp2 = *head;

    while(temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp2->next;
        temp1 = temp1->next;
        temp1 = temp1->next;
        x++;
        y+=2;

        if(temp1 == temp2)
        {
            printf("\n\nLoop Detected have position %d and %d\n\n",x,y);
            return;
        }
    }

    printf("\n\nNo Loop Detected\n\n");    
}

int main()
{
    node *head = end(10);
    head->next = end(20);
    head->next->next = end(30);
    head->next->next->next = end(40);
    head->next->next->next->next = end(50);
    head->next->next->next->next->next = head->next->next;
    
    loopdetect(&head);

}