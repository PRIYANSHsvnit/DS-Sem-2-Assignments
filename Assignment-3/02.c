#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
}node;

void create(node **head, int num);
void display(node *head);

void main()
{
    node *head = NULL;
    int n,m;

    printf("Enter Number to put in data of LL 01 =\n");
    scanf("%d",&n);

    create(&head,n);

    printf("Enter Number to put in data of LL 02 =\n");
    scanf("%d",&m);

    create(&head,m);

    display(head);
}

void create(node **head,int num)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        new->next = *head;
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
        printf("\nAddress itself = %u , Data = %d , Address = %u",temp,temp->data,temp->next);
        temp = temp->next;
    }
    
}