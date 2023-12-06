#include<stdio.h>

void SS(int A[],int n)
{
	int min,t;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		if(A[j]<A[min])
		min=j;
		
		t=A[min];
		A[min]=A[i];
		A[i]=t;
	}
	for(int i=0;i<n;i++)
	printf("%d ",A[i]);
	
}

int main()
{
	int n;
	printf("Enter no of elements present in the array ");
	scanf("%d",&n);
	int A[n];
	printf("Enter the Elements\n");
	for(int i=0;i<n;i++)
	{
		printf("Element no %d ",i+1);
		scanf("%d",&A[i]);	
	}
	SS(A,n);
	
	return 0;
}
