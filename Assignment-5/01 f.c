#include<stdio.h>
#include<stdlib.h>

typedef struct cll
{
    int data;
    struct cll *next;
    struct cll *prev;
}node;

void ccn(node **head,int num)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        new->next = new;
        new->prev = new;
        return;
    }

    node *temp = (*head)->prev;
    
    temp->next = new;
    new->prev = temp;
    new->next = *head;
    (*head)->prev = new;

}

void enddel(node **head)
{
    node *temp = *head;
    
    while(temp->next != *head)
    {
        temp = temp->next;
    }
    
    (*(temp->prev)).next = temp->next;
    (*(temp->next)).prev = temp->prev;

}

void display(node *head)
{

    node *temp = head;
    
    if(temp == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    do
    {
        printf("\nAddress itself = %u , Data = %d , Prev-Address = %u , Next-Address = %u",temp,temp->data,temp->prev,temp->next);
        temp = temp->next;
    }while(temp != head);
    
}


int main()
{
    node *head = NULL;
    int n,m,l;

    printf("Enter How Many LL = \n");
    scanf("%d",&m);

    printf("\nEnter LL Data \n\n");

    for(int i=0;i<m;i++)
    {
        printf("Enter for LL %d = \n",i+1);
        scanf("%d",&n);

        ccn(&head,n);
    }

    display(head);

    printf("\n\nDeleted Node at End = \n\n");

    enddel(&head);

    display(head);
    
}