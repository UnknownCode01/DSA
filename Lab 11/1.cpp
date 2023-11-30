//Linear search
#include<stdio.h>

int main()
{
	int n,key,count=0;
	printf("Enter the size of array ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the numbers\n");
	for(int i=0;i<n;i++)
	{
		printf("Element no %d : ",i+1);
		scanf("%d",&a[i]);		
	}
	printf("Enter element to search ");
	scanf("%d",&key);
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("Element found at index %d",i);
			count=1;
			break;
		}
	}
	if(count==0)
	printf("Element not Found");
}
