#include<stdio.h>
#include<stdlib.h>

int readmatrix(int **a,int n);
int compute(int **a,int **b,int **c,int n);
int show(int **a,int n);

int main()
{
    int n;

    printf("Enter order of matrix = \n");
    scanf("%d",&n);

    int **a = (int**)malloc(n*sizeof(int*));
    int **b = (int**)malloc(n*sizeof(int*));
    int **c = (int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++)
    {
        a[i] = (int *)malloc(n*sizeof(int));
        b[i] = (int *)malloc(n*sizeof(int));
        c[i] = (int *)malloc(n*sizeof(int));
    }

    printf("Enter Entries of Matrix A = \n");
    readmatrix(a,n);

    printf("Enter Entries of Matrix B = \n");
    readmatrix(b,n);

    compute(a,b,c,n);

    printf("Resultant Matrix = \n");
    show(c,n);

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

}

int readmatrix(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

int compute(int **a,int **b,int **c,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j] = 0;

            for(int k=0;k<n;k++)
            {
                c[i][j] += (a[i][k])*(b[k][j]);
            }

        }
    }
}

int show(int **a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }

        printf("\n");
    }
}
