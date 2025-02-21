#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} stack;

void init(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    return (s->top == -1);
}

int isFull(stack *s) {
    return (s->top == MAX - 1);
}

void push(stack *s, int value) 
{
    if (isFull(s)) 
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    s->items[++(s->top)] = value;
}

int pop(stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return (s->items[(s->top)--]);
}

int evaluate(char *exp) 
{
    stack s;
    init(&s);

    for (int i = 0; exp[i] != '\0'; i++) 
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            push(&s, ch - '0');
        } 
        
        else 
        {  
            int op2 = pop(&s);
            int op1 = pop(&s);
            int result;

            switch (ch) 
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': 
                    if (op2 == 0)
                    {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }

                    result = op1 / op2; 
                    break;

                default:
                    printf("Invalid operator encountered: %c\n", ch);
                    exit(1);
            }
            
            push(&s, result);
        }
    }

    return pop(&s);
}

int main() 
{
    char exp[MAX];

    printf("Enter Expression = \n");
    fgets(exp,MAX,stdin);
    exp[strcspn(exp,"\n")] = '\0';
    
    int result = evaluate(exp);
    printf("Result = %d\n", result);
    
}