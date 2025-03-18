#include<stdio.h>

int merge(int *a,int low,int mid,int high)
{
    int count = 0;
    int i = low;
    int j = mid+1;
    int k = 0;

    int b[high-low+1];

    while(i<=mid && j<=high)
    {
        if(a[i]>a[j])
        {
            b[k] = a[j];
            j++;
            k++;
            count += mid - i + 1;
        }
        
        else
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    while(j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    while(i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    for(int i=low,k=0;i<=high;k++,i++)
    {
        a[i] = b[k];
    }

    return count;
}

int mergedsort(int *a,int low ,int high)
{
    int incount = 0;

    if(low<high)
    {
        int mid = (low+high)/2;
        incount += mergedsort(a,low,mid);
        incount += mergedsort(a,mid+1,high);
        incount += merge(a,low,mid,high);
    }

    return incount;
}
int main()
{
    int n,t;
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

    printf("\n\n Enter Number of Test Cases = \n");
    scanf("%d",&t);

    for(int i=0;i<t;i++)
    {
        int h,l;

        printf("\nEnter Low and High Position = \n");
        scanf("%d%d",&l,&h);

        printf("\nNumber of Inversions = %d",mergedsort(arr,l,h));

        printf("\n\nAfter Sorting...\n\n");

        for(int i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
}