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


void begin(node **head, int num) {
    node *new = (node *)malloc(sizeof(node));
    new->data = num;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL) {
        *head = new;
        new->next = new;
        new->prev = new;
        return;
    }

    node *temp = (*head)->prev;

    new->next = *head;
    new->prev = temp;
    
    temp->next = new;
    (*head)->prev = new;
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

    do
    {
        printf("\nAddress itself = %u , Data = %d , Prev-Address = %u , Next-Address = %u",temp,temp->data,temp->prev,temp->next);
        temp = temp->next;
    }while(temp != head);
    
}


int main()
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

        ccn(&head,n);
    }

    display(head);

    printf("\n\nEnter the Node Data which you want to enter in the beginning of LL Created Before  = \n");
    scanf("%d",&o);

    begin(&head,o);

    display(head);
    
}