#include<stdio.h>

void countingsort(int *arr,int n,int k)
{
    int cout[k+1];
    int b[n];

    for(int i=0;i<=k;i++)
    {
        cout[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        cout[arr[i]]++;
    }

    int s = 0;
    int count[k+1];

    for(int i=0;i<=k;i++)
    {
        s += cout[i];
        count[i] = s;
    }

    for(int i=n-1;i>=0;i--)
    {
        b[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = b[i];
    }
}

int main()
{
    int n;
    printf("Enter The size of array you wanna sort\n");
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter Number %d = \n",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\n\nBefore Sorting...\n\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    int k;

    printf("\nEnter Condition K = \n");
    scanf("%d",&k);

    countingsort(arr,n,k);

    printf("\n\nAfter Sorting...\n\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}