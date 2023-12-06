#include<stdio.h>

int main()
{
	int n,count=0;
	printf("Enter no of elements present in a graph ");
	scanf("%d",&n);
	int N[n];
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
	{
		printf("Element no %d :",i+1);
		scanf("%d",&N[i]);
	}
	int A[n][n];
	printf("Enter If Edge is present(0/1)\n");
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("%d -> %d ",N[i],N[j]);
		scanf("%d",&A[i][j]);
		if(A[i][j]==1)
		count++;	
	}
	printf("The no of edges present in the Graph is %d",count/2);
	
	return 0;
}
