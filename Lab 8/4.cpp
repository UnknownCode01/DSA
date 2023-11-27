#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int info;
	struct Node* Next;
	struct Node* Prev;
}*Front,*Rear;

void Insert_at_Front(int t)
{
	struct Node*New;
	New=(struct Node*)malloc(sizeof(struct Node));
	New->info=t;
	New->Next=Front;
	New->Prev=NULL;
	Front->Prev=New;
	Front=New;
	
}
void Insert_at_Rear(int t)
{
	struct Node*New;
	New=(struct Node*)malloc(sizeof(struct Node));
	New->info=t;
	New->Next=NULL;
	New->Prev=Rear;
	Rear->Next=New;
	Rear=New;
}
void Insert(int t)
{
	struct Node*New;
	New=(struct Node*)malloc(sizeof(struct Node));
	New->info=t;
	New->Next=NULL;
	New->Prev=NULL;
	Front=New;
	Rear=New;
}
void Del_from_Front()
{
	int Value;
	struct Node* temp;

		Value=Front->info;
		temp=Front;
		Front=Front->Next;
		Front->Prev=NULL;

	free(temp);
	printf("Deleted item is %d\n",Value);
}

void Del_from_Rear()
{
	int Value;
	struct Node* temp;

		Value=Rear->info;
		temp=Rear;
		Rear=Rear->Prev;
		Rear->Next=NULL;
		
	free(temp);
	printf("Deleted item is %d\n",Value);
}

void Del()
{
	int Value;
	struct Node* temp;
		
	Value=Rear->info;
	temp=Rear;
	Front=NULL;
	Rear=NULL;
	free(temp);
	printf("Deleted item is %d\n",Value);
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
		int t,t1;
		case 1:	
		printf("Enter the Number to Enqueue ");
		scanf("%d",&t);
		if(Front==NULL && Rear==NULL)
		{
			Insert(t);
			break;
		}	
		else{
		printf("Select position\n1.At Front\t2.At Rear\n");
		scanf("%d",&t1);
			if(t1==1)	
			Insert_at_Front(t);
			else if(t1==2)
			Insert_at_Rear(t);
			else
			printf("Incorrect Option\n");
			break;
		}
		case 2:
			if(Front==NULL && Rear==NULL)
			{
				printf("Underflow\n");
				break;
			}
			else if(Front==Rear)
			{
				Del();
				break;
			}
			else{
			printf("Select position\n1.From Front\t2.From Rear\n");
			scanf("%d",&t1);
			if(t1==1)
			Del_from_Front();
			else if(t1==2)
			Del_from_Rear();
			else
			printf("Incorrect Option\n");
			break;
			}
		case 3:
			TRAVERSAL();	
			break;
		case 4:
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
	printf("1.Enqueue\n2.Dequeue\n3.Display elements\n4.IsEmpty\n5.Exit\n\n");
	while(1){
	printf("\nOption : ");
	scanf("%d",&c);
	if(c==5)
	break;
	choose(c);	
	}
	return 0;
}
