#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
}node;

void create(node **head, int num);
void traverse(node *head);

void main()
{
    node *head = NULL;
    int n,m;

    printf("Enter How Many LL you wanna Enter = \n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        printf("Enter Number to put in data of LL %d = \n",i);
        scanf("%d",&m);

        create(&head,m);
    }

    traverse(head);
    
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

void traverse(node *head)
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