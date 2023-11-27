#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int info;
	struct Node*Next;
}*Front,*Rear;

void ENQUEUE(int Item)
{
	struct Node*New;
	New=(struct Node*)malloc(sizeof(struct Node));
	New->info=Item;
	New->Next=NULL;
	if(Front==NULL && Rear==NULL)
	{
		Front=New;
		Rear=New;
	}
	else
	{
		Rear->Next=New;
		Rear=New;
	}
}
void DEQUEUE()
{
	int Value;
	struct Node* temp;
	if(Front==NULL && Rear==NULL)
	{
		printf("UNDERFLOW");
		return;	
	}
	else if(Front==Rear)
	{
		Value=Front->info;
		temp=Front;
		Front=NULL;
		Rear=NULL;
	}
	else
	{
		Value=Front->info;
		temp=Front;
		Front=Front->Next;
	}
	free(temp);
		printf("Deleted item is %d\n",Value);
}
void PEEK()
{
	if(Front==NULL)
	printf("No elements.");
	else
	printf("Peek element is %d\n",Front->info);
}
void TRAVERSAL()
{
	if(Front==NULL)
	printf("No elements are in Queue\n");
	else{
	struct Node*ptr;
	ptr=Front;
	printf("Showing Elements\n");
	while(ptr!=Rear)
	{
		printf("%d ",ptr->info);
		ptr=ptr->Next;
	}
	printf("%d\n",ptr->info);
	}
}

void IsEmpty()
{
	if(Front==NULL)
	printf("Queue is Empty\n");
	else
	printf("Queue is not Empty\n");
}
void choose(int c)
{
	switch(c)
	{
		int t;
		case 1:		
			printf("Enter the Number to Enqueue ");
			scanf("%d",&t);	
			ENQUEUE(t);
			break;
		case 2:
			DEQUEUE();
			break;
		case 3:
			PEEK();
			break;
		case 4:
			TRAVERSAL();
			break;
		case 5:
			IsEmpty();
			break;
		default :
			printf("Incorrect Option\n");
			break;				
	}	
}

int main()
{
	Front=Rear=NULL;
	int c;
	printf("Select from below options\n");
	printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display elements\n5.IsEmpty\n6.Exit\n\n");
	while(1){
	printf("\nOption : ");
	scanf("%d",&c);
	if(c==6)
	break;
	choose(c);	
	}
	return 0;
}
