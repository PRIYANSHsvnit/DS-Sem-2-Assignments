#include<stdio.h>
int main()
{
	int n,count=0;
	
	printf("Enter N\n");
	scanf("%d",&n);
	
	int a[n];
	
	printf("Enter set of numbers \n");
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((j>i)&&(a[i]>a[j]))
			{
				count++;
			}
		}
	}
	
	printf("Number Of Permutations = %d",count);
	
}