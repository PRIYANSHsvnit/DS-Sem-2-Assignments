#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct ll
{
    int data;
    int arr[MAX];
}stack;

void cs(stack *s)
{
    s->data = -1;
}

void push(stack *s, int num)
{
    if (s->data == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s->arr[++s->data] = num;
}

void pop(stack *s)
{
    if (s->data == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    s->data--;
}

void display(stack *s)
{
    if (s->data == -1)
    {
        printf("Stack is Empty \n");
        return;
    }

    for (int i = s->data; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}

void main()
{
    stack ques;
    int x,y;

    cs(&ques);

    printf("Enter how many elements do you wanna enter in stack = \n");
    scanf("%d",&x);

    for(int i= 0;i<x;i++)
    {
        printf("Enter element %d = \n",i+1);
        scanf("%d",&y);
        push(&ques,y);
    }

    printf("\n\nElement at top of the stack = %d\n\n",ques.arr[ques.data]);

    printf("Enter how many elements do you wanna pop from stack = \n\n");
    scanf("%d",&x);

    for(int i = 0;i<x;i++)
    {
        pop(&ques);
    }

    printf("\nFinal Representation of Stack implemented = \n\n");

    display(&ques);

}