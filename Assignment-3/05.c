#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
}node;

void create(node **head, int num);
void display(node *head);
void arraytransfer(node *head,int arr[]);

void main()
{
    node *head = NULL;
    int n,p;

    printf("Enter How Many LL You want = \n");
    scanf("%d",&p);

    for(int i=1;i<=p;i++)
    {
        printf("Enter Number to put in data of LL %d = \n",(i));
        scanf("%d",&n);

        create(&head,n);

    }

    // display(head);

    int a[p];

    arraytransfer(head,a);

    printf("Array Copied From LL = \n");

    for(int i=0;i<p;i++)
    {
        printf("%d\t",a[i]);
    }
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

// void display(node *head)
// {
//     node *temp = head;
    
//     if(temp == NULL)
//     {
//         printf("The List is Empty\n");
//         return;
//     }

//     while(temp != NULL)
//     {
//         printf("DATA = %d\n",temp->data);
//         temp = temp->next;
//     }
    
// }

void arraytransfer(node *head,int arr[])
{
    node *temp = head;
    
    if(temp == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    int j=0;

    while(temp != NULL)
    {
        arr[j] = temp->data;
        temp = temp->next;
        j++;
    }

    // return arr;
    
}