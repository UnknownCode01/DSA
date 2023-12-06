#include<stdio.h>

void IS(int A[],int n)
{
	int i=1,j=0,k;
	while(i<n)
	{
		k=A[i];
		j=i-1;
		while(j>=0 && k<A[j])
		{
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=k;
		i++;
	}
	printf("Displaying Sorted Array\n\n");
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
	IS(A,n);
	
	return 0;
}
