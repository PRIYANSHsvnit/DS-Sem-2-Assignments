#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
    int size;
    int csize;
}node;

void enqueue(node **front,node **rear,node **size,int num)
{
    if( (*size)->csize == (*size)->size)
    {
        printf("Queue IS EMPTY!\n");     // IsEmpty and LL have infinite size it can't be full
        return;
    }

    node *new = (node*)malloc(sizeof(node));

    new->data = num;
    new->next = NULL;

    if( *front == NULL)
    {
        *front = new;
        *rear = new;
        (*rear)->next = *front;     // Self Linking
        (*size)->csize++;
        return;
    }

    (*rear)->next = new;
    *rear = new;
    (*rear)->next = *front;

    (*size)->csize++;
}

int dequeue(node **front,node **rear,node **size)
{
    if( (*size)->csize == 0)
    {
        printf("Queue IS EMPTY!\n");     // IsEmpty and LL have infinite size it can't be full
        return -1;
    }

    int data = (*front)->data;

    if(*front == *rear)
    {
        *front = *rear = NULL;
    }

    else
    {
        *front = (*front)->next;
        (*rear)->next = *front;
    }

    (*size)->csize--;

    return data;
}

int peek(node **front,node **size)
{
    if( (*size)->csize == (*size)->size )
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
    do
    {
        printf("\nAddress itself = %u , Data = %d , Next-Address = %u",temp,temp->data,temp->next);
        temp = temp->next;
    } while (temp != front);
    
}

void main()
{
    int n;

    printf("Enter the size of QUEUE = \n");
    scanf("%d",&n);

    node *size1 = (node*)malloc(sizeof(node));
    (*size1).size = n;
    (*size1).csize = 0;

    node *front = NULL;   // Pointer front
    node *rear = NULL;    // Pointer rear
    int m;

    for(int i=1;i<=n;i++)
    {
        printf("Enter Number to put in data of QUEUE %d = \n",i);
        scanf("%d",&m);

        enqueue(&front,&rear,&size1,m);
    }

    printf("First Element Before Dequeue = %d\n\n",peek(&front,&size1));
    printf("\nDisplay...\n");

    display(front);

    printf("\n\nEnter How Many elements you wanna DELETE in QUEUE = \n");
    scanf("%d",&n);
    printf("\n");

    for(int i=1;i<=n;i++)
    {
        printf("DELETED ELEMENT = %d\n",dequeue(&front,&rear,&size1));
    }

    printf("\nFirst Element After Dequeue = %d\n\n",peek(&front,&size1));
    printf("Display...\n");

    free(size1);

    display(front);
}