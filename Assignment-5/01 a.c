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
    
    for(int i=1;i<num1-1;i++)
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

    do
    {
        printf("\nAddress itself = %u , Data = %d , Prev-Address = %u , Next-Address = %u",temp,temp->data,temp->prev,temp->next);
        temp = temp->next;
    }while(temp != head);
    
}


int main()
{
    node *head = NULL;
    int n,m,o,l;

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

    printf("\n\nEnter the Node Data which you want to enter in the position specified of LL Created Befor  = \n");
    scanf("%d",&o);

    printf("Enter the Node Position after you wanna Create a node = \n\n");
    scanf("%d",&l);

    aftern(&head,o,l);

    display(head);
    
}