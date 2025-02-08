#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
}stack;

void cs(stack **head)
{
    *head = NULL;
}

void push(stack **head,int num)
{
    stack *new = (stack*)malloc(sizeof(stack));

    if(new == NULL)
    {
        printf("Stack Is Overflow\n");
        exit(-1);
    }

    new->data = num;
    new->next = *head;
    *head = new;
}

void pop(stack **head)
{
    stack *p = *head;
    
    if(*head == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    
    *head = p->next;
    free(p);
}

void display(stack *head)
{

    stack *temp = head;
    
    if(temp == NULL)
    {
        printf("The Stack is Empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("\nData = %d",temp->data);
        temp = temp->next;
    }
}

void main()
{
    stack *a;
    cs(&a);

    int x,y;

    printf("Enter how many elements do you wanna enter in stack = \n");
    scanf("%d",&x);

    for(int i= 0;i<x;i++)
    {
        printf("Enter element %d = \n",i+1);
        scanf("%d",&y);
        push(&a,y);
    }

    printf("\n\nElement at top of the stack = %d\n\n",(*a).data);

    printf("Enter how many elements do you wanna pop from stack = \n\n");
    scanf("%d",&x);

    for(int i = 0;i<x;i++)
    {
        pop(&a);
    }

    printf("Final Representation of Stack implemented = \n\n");

    display(a);

}