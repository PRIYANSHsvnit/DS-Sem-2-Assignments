//Doubly linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct dll
{
    struct dll *prev;
    int data;
    struct dll *next;
}node;

void end(node **head,int num)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
    }

    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
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
        printf("\nAddress itself = %u , Data = %d , Prev-Address = %u , Next-Address = %u",temp,temp->data,temp->prev,temp->next);
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

}