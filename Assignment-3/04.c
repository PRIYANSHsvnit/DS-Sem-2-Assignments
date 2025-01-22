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
    int p;

    printf("Enter How Many LL You want = \n");
    scanf("%d",&p);

    int a[p];

    printf("Enter Array Elements in which you want to copy = \n");
    
    for(int i=0;i<p;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<p;i++)
    {
       create(&head,a[i]);
    }

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
        return;
    }
    
    node *temp = *head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
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
        printf("\nAddress itself = %u , Data = %d , Address = %u",temp,temp->data,temp->next);
        temp = temp->next;
    }
    
}