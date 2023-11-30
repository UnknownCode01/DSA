#include<stdio.h>

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void bubblesort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
	if(arr[j]>arr[j+1])
	swap(arr[j],arr[j+1]);		
}
int main()
{
	int n;
	printf("Enter the array size ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements\n");
	for(int i=0;i<n;i++)
	{
		printf("Element no %d ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Array before sorting\n\n");
	for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
	bubblesort(arr,n);
	printf("\n\nSorted Array\n\n");
	for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	return 0;
}
