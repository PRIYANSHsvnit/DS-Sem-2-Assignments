#include<stdio.h>

void bubblesort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter The size of array you wanna sort\n\n");
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

    bubblesort(arr,n);

    printf("\n\nAfter Sorting...\n\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}