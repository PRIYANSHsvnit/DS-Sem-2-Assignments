#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct ll
{
    char data;
    struct ll *next;
}node;


void create(node **head,char num)
{
    node *new = (node*)malloc(sizeof(node));

    if(new == NULL)
    {
        printf("Stack is Overflow\n\n");
        return;
    }

    new->data = num;
    new->next = *head;

    *head = new;
}

char remove1(node **head)
{
    if(*head == NULL)
    {
        printf("Stack is Undeerflow\n\n");
        exit(1);
    }

    node *temp = *head;
    char value = temp->data;
    *head = temp->next;
    free(temp);
    return value;
}

char peek(node *head)
{
    if(head == NULL)
    {
        return '\0';
    }

    else
    {
        return head->data;
    }
}

int empty(node *head)
{
    if(head != NULL)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

int preced(char op)
{
    if( op == '+' ||  op == '-')
    {
        return 1;
    }

    if( op == '*' ||  op == '/')
    {
        return 2;
    }

    if( op == '^')
    {
        return 3;
    }

    else
    {
        return 0;
    }
}

int isop(char op)
{
    if( op == '+' ||  op == '-' || op == '*' ||  op == '/' || op == '^')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void inftopost(char* inf, char* post) {
    node *temp = NULL;
    int i=0,j=0;

    char ch;

    while ((ch = inf[i++]) != '\0') 
    {
        if (isalnum(ch)) 
        {
            post[j++] = ch;
        }

        else if (ch == '(') 
        {
            create(&temp, ch);
        }

        else if (ch == ')') 
        {
            while (!empty(temp) && peek(temp) != '(')
            {
                post[j++] = remove1(&temp);
            }

            if (!empty(temp) && peek(temp) == '(')
            {
                remove1(&temp);
            }
        }

        else if (isop(ch)) 
        {
            while (!empty(temp) && ((preced(peek(temp)) > preced(ch)) || (preced(peek(temp)) == preced(ch) && ch != '^')))
            {
                post[j++] = remove1(&temp);
            }

            create(&temp, ch);
        }
    }

    while (!empty(temp)) 
    {
        post[j++] = remove1(&temp);
    }

    post[j] = '\0';
}

void main()
{
    int n;

    printf("Enter String Size of Operation which you wanna perform = \n");
    scanf("%d",&n);

    getchar();

    char infix[n+1];
    char postfix[n+1];

    printf("\nEnter infix expression = \n");
    fgets(infix,sizeof(infix),stdin);

    infix[strcspn(infix, "\n")] = '\0';

    inftopost(infix, postfix);

    printf("\nPostfix expression = %s\n\n", postfix);
    
}