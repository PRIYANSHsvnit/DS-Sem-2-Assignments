#include<stdio.h>
#include<stdlib.h>

typedef struct dll
{
    struct dll *prev;
    int data;
    struct dll *next;
}node;

void First(node **head,int num)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = num;
    new->prev = NULL;
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
    new->prev = temp;
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

int main()
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

        First(&head,n);
    }

    display(head);

}