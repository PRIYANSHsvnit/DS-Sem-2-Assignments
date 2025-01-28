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

void rotation(node **head)
{
    node *temp = *head;
    node *prev = NULL;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL)
    {
        temp->next = *head;
        prev->next = NULL;
        *head = temp;
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
    int n,m,o;

    printf("Enter How Many LL = \n");
    scanf("%d",&m);

    printf("\nEnter LL Data \n\n");

    for(int i=0;i<m;i++)
    {
        printf("Enter for LL %d = \n",i+1);
        scanf("%d",&n);

        end(&head,n);
    }

    printf("Before Rotation = \n\n");

    display(head);

    printf("\n\nHow many times do you wanna Rotate it = \n");
    scanf("%d",&o);

    for(int i=0;i<o;i++)
    {
        rotation(&head);
    }

    printf("\nAfter Rotation Operation = \n\n");

    display(head);
}