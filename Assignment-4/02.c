#include<stdio.h>
#include<stdlib.h>

typedef struct dll
{
    int data;
    struct dll *next;
}node;

void end(node **head,int num)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        return;
    }

    node *lnode = *head;

    while(lnode->next != NULL)
    {
        lnode = lnode->next;
    }
    
    lnode->next = new;
}

void duplicate(node **head)
{
    node *temp = *head;
    
    while(temp != NULL)
    {
        node *prev = temp->next;
        node *extra = temp;

        while(prev != NULL)
        {
            if(prev->data == temp->data)
            {
                printf("\n Duplicate Found\n\n");
                extra->next = prev->next;
            }

            extra = prev;
            prev = prev->next;
        }

        temp = temp->next;
    }
}

void display(node *head)
{
    node *temp = head;
    
    if(temp == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("\nAddress itself = %u , Data = %d , Next-Address = %u",temp,temp->data,temp->next);
        temp = temp->next;
    }
}

void main()
{
    node *head = NULL;
    int n,m;

    printf("Enter How Many LL = \n");
    scanf("%d",&m);

    printf("\nEnter LL Data \n\n");

    for(int i=0;i<m;i++)
    {
        printf("Enter for LL %d = \n",i+1);
        scanf("%d",&n);

        end(&head,n);
    }

    display(head);

    printf("\nAfter Duplicate deletion Operation = \n\n");

    duplicate(&head);

    display(head);
}