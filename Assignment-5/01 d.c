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

void afterndel(node **head,int num1)
{
    node *temp = *head;
    temp = temp->next;
    node *temp1 = *head;
    
    for(int i=1;i<num1-1;i++)
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    
    temp1->next = temp->next;
    (*(temp->next)).prev = temp1;

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

    printf("\n\nEnter the Node Position after you wanna delete a node = \n\n");
    scanf("%d",&l);

    afterndel(&head,l);

    display(head);
    
}