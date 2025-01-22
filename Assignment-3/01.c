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
    int n;

    printf("Enter Number to put in data of LL =\n");
    scanf("%d",&n);

    create(&head,n);

    display(head);
}

void create(node **head,int num)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->next = NULL;

    *head = new;
}

void display(node *head)
{
    node *temp = head;
    
    if(temp == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    printf("\nAddress itself = %u , Data = %d , Address = %u",temp,temp->data,temp->next);
    
}