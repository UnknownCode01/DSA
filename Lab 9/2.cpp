#include<stdio.h>
#include<stdlib.h>

struct Tree
{
	int data;
	struct Tree *lc,*rc;
};

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

void display(struct Tree *t)
{
	if(t)
	{
		printf("%d ",t->data);	
		display(t->lc);
		display(t->rc);
	}
	else
	{
		printf("_ ");
	}
}

int main()
{
	struct Tree *Root;
	Root=(struct Tree *)malloc(sizeof(struct Tree));
	buildtree(Root);
	printf("\nDisplaying in Preorder\n\n");
	display(Root);
	
	return 0;
}
