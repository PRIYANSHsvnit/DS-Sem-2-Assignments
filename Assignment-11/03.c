#include<stdio.h>

int max(int arr[], int n)
{
    int max = arr[0];

    for (int i=1;i<n;i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void countingsort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/exp) % 10]++ ;
    }

    for (int i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }

    for (int i= n-1;i>=0;i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]-- ;
    }

    for (int i=0;i<n;i++)
    {
        arr[i] = output[i];
    }  
}

void radixsort(int arr[], int n)
{
    int maxx = max(arr, n);

    for (int exp=1;maxx/exp > 0;exp *= 10)
    {
        countingsort(arr, n, exp);
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

    radixsort(arr,n);

    printf("\n\nAfter Sorting...\n\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}