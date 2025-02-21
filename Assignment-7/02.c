#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
}node;

void enqueue(node **front,node **rear,int num)
{
    node *new = (node*)malloc(sizeof(node));

    new->data = num;
    new->next = NULL;

    if( *front == NULL)
    {
        *front = new;
        *rear = new;
        return;
    }

    (*rear)->next = new;
    *rear = new;
}

int dequeue(node **front,node **rear)
{
    if( *front == NULL)
    {
        printf("Queue IS EMPTY!\n");     // IsEmpty and LL have infinite size it can't be full
        return -1;
    }

    int data = (*front)->data;
    (*front) = (*front)->next;

    if( *front == NULL)
    {
        *rear = NULL;
    }

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
        printf("\nAddress itself = %u , Data = %d , Next-Address = %u",temp,temp->data,temp->next);
        temp = temp->next;
    }
    
}

void main()
{
    node *front = NULL;   // Pointer front
    node *rear = NULL;    // Pointer rear
    int n,m;

    printf("Enter How Many elements you wanna Enter in QUEUE = \n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        printf("Enter Number to put in data of QUEUE %d = \n",i);
        scanf("%d",&m);

        enqueue(&front,&rear,m);
    }

    printf("First Element Before Dequeue = %d\n\n",peek(&front));
    printf("\nDisplay...\n");

    display(front);

    printf("\n\nEnter How Many elements you wanna DELETE in QUEUE = \n");
    scanf("%d",&n);
    printf("\n");

    for(int i=1;i<=n;i++)
    {
        printf("DELETED ELEMENT = %d\n",dequeue(&front,&rear));
    }

    printf("\nFirst Element After Dequeue = %d\n\n",peek(&front));
    printf("Display...\n");

    display(front);
}