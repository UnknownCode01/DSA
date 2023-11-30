//Linear or Binary Search
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

void ls(int a[],int n)
{
	int key;
	int count=0;
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

void sort(int a[],int n)
{
	int temp;
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	if(a[i]>a[j])
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;	
	}
}

void get(int a[],int n)
{
	printf("Enter the numbers\n");
	for(int i=0;i<n;i++)
	{
		printf("Element no %d : ",i+1);
		scanf("%d",&a[i]);		
	}
	sort(a,n);
	
}
void pass(int ch,int a[],int n,int key)
{
	switch(ch)
	{
		case 1:
			get(a,n);
			ls(a,n);
			break;
		case 2:
			get(a,n);
			printf("Enter element to search ");
			scanf("%d",&key);
			int result=bs(a,0,n-1,key);
			(result==-1)
			?printf("Element is not present in the array.")
			:printf("Element is present at index %d",result);
			break;
	}
}

int main()
{
	int n,key;
	
	printf("Enter the size of array ");
	scanf("%d",&n);
	int a[n];
	printf("\nSelect from below options\n1.Linear Search\t\t2.Binary Search\n");
	int ch;
	scanf("%d",&ch);
	pass(ch,a,n,key);
	
	return 0;
}
