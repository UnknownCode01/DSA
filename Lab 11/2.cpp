//Binary Search
#include<stdio.h>

int bs(int a[],int l,int r,int x)
{
if(r>=l)
{
	int mid=l+(r-l)/2;
	
	if(a[mid]==x)
	return mid;
	
	if(a[mid]>x)
	return bs(a,l,mid-1,x);
	return bs(a,mid+1,r,x);
}
return -1;
}

int main()
{
	int n,key,count=0;
	printf("Enter the size of array ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the numbers in sorted manner\n");
	for(int i=0;i<n;i++)
	{
		printf("Element no %d : ",i+1);
		scanf("%d",&a[i]);		
	}
	printf("Enter element to search ");
	scanf("%d",&key);
	int result=bs(a,0,n-1,key);
	(result==-1)
	?printf("Element is not present in the array.")
	:printf("Element is present at index %d",result);
	
	return 0;
}
