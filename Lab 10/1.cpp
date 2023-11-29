#include<stdio.h>
#include<stdlib.h>

struct Tree
{
	int data;
	struct Tree *lc,*rc;
};

	struct Tree *Root,*ptr;
	struct Tree *Stack[100];
    int Top=0;
    int Maxsize=99;

void INORD()
{
	Top=0;
	Stack[Top]=NULL;
	ptr=Root;
	printf("\nDisplaying Inorder Traversal without recursion\n\n");
	while(ptr!=NULL)
	{
	while(ptr!=NULL)
	{
		Top=Top+1;
		Stack[Top]=ptr;
		ptr=ptr->lc;
	}
	ptr=Stack[Top];
	while(ptr!=NULL)
	{
	    ptr=Stack[Top];
		printf("%d ",ptr->data);
	    Top=Top-1;
		if(ptr->rc!=NULL)
		{	ptr=ptr->rc;
			break;
		}
	}
	}
}

void buildtree(struct Tree *ptr)
{
	struct Tree *New;
	int ch;
	printf("Enter value ");
	scanf("%d",&ptr->data);
	ptr->lc=NULL;
	ptr->rc=NULL;
	printf("Do you want to add left child of %d (0/1) ? ",ptr->data);
	scanf("%d",&ch);
	if(ch)
	{
		New=(struct Tree *)malloc(sizeof(struct Tree));
		ptr->lc=New;
		buildtree(New);
	}
	printf("Do you want to add right child of %d (0/1) ? ",ptr->data);
	scanf("%d",&ch);
	if(ch)
	{
		New=(struct Tree *)malloc(sizeof(struct Tree));
		ptr->rc=New;
		buildtree(New);
	}
}

int main()
{
	Root=(struct Tree *)malloc(sizeof(struct Tree));
	buildtree(Root);
	INORD();
	
	return 0;
}
