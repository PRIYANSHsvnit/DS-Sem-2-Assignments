#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    int pr;
    struct ll *next;
}node;

void enqueue(node **front,int num,int pri)
{
    node *new = (node*)malloc(sizeof(node));

    new->data = num;
    new->next = NULL;
    new->pr = pri;

    if( *front == NULL || (*front)->pr < pri)
    {
        new->next = *front;
        *front = new;
        return;
    }

    node *temp = *front;

    while(temp->next != NULL && temp->next->pr >= pri)
    {
        temp = temp->next;
    }
    
    new->next = temp->next;
    temp->next = new;
}

int dequeue(node **front)
{
    if( *front == NULL)
    {
        printf("Queue IS EMPTY!\n");     // IsEmpty and LL have infinite size it can't be full
        return -1;
    }

    int data = (*front)->data;
    (*front) = (*front)->next;

    return data;
}

int peek(node **front)
{
    if( *front == NULL)
    {
        printf("QUEUE is EMPTY!\n");
        return -1;
    }

    return (*front)->data;
}

void display(node *front)
{
    node *temp = front;
    
    if(temp == NULL)
    {
        printf("The Queue is Empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("\nAddress itself = %u , Data = %d , Priority = %d , Next-Address = %u",temp,temp->data,temp->pr,temp->next);
        temp = temp->next;
    }
    
}

void main()
{
    node *front = NULL;   // Pointer front
    int n,m,x;

    printf("Enter How Many elements you wanna Enter in QUEUE = \n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        printf("Enter Number to put in data of QUEUE %d = \n",i);
        scanf("%d",&m);

        printf("Enter Priority = \n");
        scanf("%d",&x);

        enqueue(&front,m,x);
    }

    printf("First Element Before Dequeue = %d\n\n",peek(&front));
    printf("\nDisplay...\n");

    display(front);

    printf("\n\nEnter How Many elements you wanna DELETE in QUEUE = \n");
    scanf("%d",&n);
    printf("\n");

    for(int i=1;i<=n;i++)
    {
        printf("DELETED ELEMENT = %d\n",dequeue(&front));
    }

    printf("\nFirst Element After Dequeue = %d\n\n",peek(&front));
    printf("Display...\n");

    display(front);
}