#include<stdio.h>
#include<stdlib.h>

typedef struct members
{
    int *a;
    int *b;

}mem;

int main()
{
    mem *m_1 = (mem*)malloc(sizeof(mem));

    int n;

    printf("Enter length of array A = \n");
    scanf("%d",&n);

    m_1->a = (int*)malloc(n*sizeof(int));
    m_1->b = (int*)malloc(n*sizeof(int));

    printf("Enter Elements of Array A = \n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",(m_1->a + i));
    }

    for(int i=0;i<n;i++)
    {
        *(m_1->b + i) = *(m_1->a + i) ;
    }

    printf("Array B Before = \n");

    for(int i=0;i<n;i++)
    {
        printf(" %d",*(m_1->b + i));
    }

    for(int i=0;i<n;i++)
    {
        if(i%2 && (i!=(n-1)))
        {
           *(m_1->b + i) = (*(m_1->b + (i-1)))*(*(m_1->b + (i+1))) ;
        }

        else continue ;
    }

    printf("\n\nArray B After = \n");

    for(int i=0;i<n;i++)
    {
        printf(" %d",*(m_1->b + i));
    }
    
}