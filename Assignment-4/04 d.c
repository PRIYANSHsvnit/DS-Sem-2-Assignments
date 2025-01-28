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

void aftern(node **head,int num,int num1)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->prev = NULL;
    new->prev = NULL;

    if(*head == NULL)
    {
        *head = new;
        return;
    }


    node *temp = *head;
    
    for(int i=1;i<(num1/2)+1;i++)
    {
        temp = temp->next;
    }
    
    new->next = temp->next;
    new->prev = temp;
    temp->next = new;

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
    int l,o,n,m;

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

    printf("\n\nEnter the Node Data which you want to enter in the position specified of LL Created Befor  = \n");
    scanf("%d",&o);

    printf("Enter the Node Position after you wanna Create a node = \n\n");
    scanf("%d",&l);

    aftern(&head,o,m);

    display(head);

}