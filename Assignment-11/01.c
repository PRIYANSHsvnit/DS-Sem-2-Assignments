#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = low; 

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

int quicksort(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);

        if (pi == k)
        {
            return arr[pi];
        }
        
        else if (pi > k)
        {
            return quicksort(arr, low, pi - 1, k);
        }
        
        else
        {
            return quicksort(arr, pi + 1, high, k);
        }
            
    }

    return -1;
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

    int k;

    printf("\n Enter the Kth smallest Number you wanna find = \n");
    scanf("%d",&k);

    int kth = quicksort(arr,0,n-1,k-1);

    printf("\n Kth Element = %d",kth);
}