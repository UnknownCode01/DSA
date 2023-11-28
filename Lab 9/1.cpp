#include<stdio.h>

void buildtree(int t[],int index,int value)
{
	int ch,data;
	t[index]=value;
	printf("Do yiu have left child of %d (0/1) ? ",value);
	scanf("%d",&ch);
	if(ch)
	{
		printf("Enter the left child ");
		scanf("%d",&data);
		buildtree(t,2*index+1,data);
	}
	
	printf("Do you have right child of %d (0/1) ? ",value);
	scanf("%d",&ch);
	if(ch)
	{
		printf("Enter the right child ");
		scanf("%d",&data);
		buildtree(t,2*index+2,data);
	}
}

void display(int t[])
{
	for(int i=0;i<20;i++)
	{
		if(t[i]==-1)
		printf("_ ");
		else
		printf("%d ",t[i]);
	}
	
}

int main()
{
	int t[20],index,value;
	
	for(int i=0;i<20;i++)
	t[i]=-1;
	
	printf("Enter the root node ");
	scanf("%d",&value);
	buildtree(t,0,value);
	display(t);
	
	return 0;
}
