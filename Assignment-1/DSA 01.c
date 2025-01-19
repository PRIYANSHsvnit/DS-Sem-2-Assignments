#include<stdio.h>
int main()
{
	int n,max;
	
	printf("Enter N \n");
	scanf("%d",&n);
	
	int a[n];
	
	printf("Enter Set Of Numbers \n");
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}

		else if(a[i]<a[i-1])
		{
			break;
		}

	}

	printf("\nMaximum From Given Set = %d ",max);
	
	return 0;
	
}