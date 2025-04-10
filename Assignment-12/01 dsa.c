#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* createnode(int data)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

void llsort(node* head)
{
    if (!head) return;

    int swapped;
    node* ptr1;
    node* lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }

            ptr1 = ptr1->next;
        }

        lptr = ptr1;

    } while (swapped);

}

void printbucket(node *bucket, int m)
{
    for(int i=0;i<m;i++)
    {
        printf("Bucket %d (idx = %d) = ",i+1,i);

        node *temp = bucket[i].next;

        while(temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

void bucketsort(int *arr,int n,int m)
{
    node *bucket = (node*)calloc(m,sizeof(node));

    for(int i=0;i<m;i++)
    {
        bucket[i].next = NULL;
    }

    for(int i=0;i<n;i++)
    {
        int value = arr[i]%m;
        if(! bucket[value].next)
        {
            bucket[value].next = createnode(arr[i]);
        }
        else
        {
            node *temp = (bucket[value].next);
            while((temp)->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = createnode(arr[i]);

        }
    }
    printf("Buckets Before sorting = \n\n");
    printbucket(bucket,m);

    for(int i=0;i<m;i++)
    {
        if(! bucket[i].next) continue;
        llsort(bucket[i].next);
    }

    int count = 0;

    for(int i=0;i<m;i++)
    {
        if(bucket[i].next)
        {
            node *temp = (bucket[i].next);

            while(temp)
            {
                arr[count++] = temp->data;
                temp = temp->next;
            }
        }
    }

    printf("\n\n");
    printf("Buckets After sorting = \n\n");
    printbucket(bucket,m);
    free(bucket);
}

int main()
{
    int n;

    printf("Enter Array Size = \n");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter Array = \n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int m;

    printf("\nEnter Bucket Size = \n");
    scanf("%d",&m);

    printf("Display before sorting...\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\n\n");

    bucketsort(arr,n,m);

    printf("\n\nDisplay after sorting...\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    
}