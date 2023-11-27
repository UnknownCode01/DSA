#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int info;
	int Pr;
	struct Node* Next;
}*Front,*Rear;

void Insert(int t,int Pr)
{
	struct Node *New,*ptr;
	New=(struct Node*)malloc(sizeof(struct Node));
	New->info=t;
	New->Next=NULL;
	New->Pr=Pr;
	if(Front==NULL){
		Front=New;
		Rear=New;
	}
	else if(Front==Rear)
	{
		ptr=Front;
			if(ptr->Pr<=New->Pr)
			{
				ptr->Next=New;
				Rear=New;
			}
			else
			{
				New->Next=ptr;
				Front=New;
			}
	}	
	else
	{
		ptr=Front;
		if(ptr->Pr>New->Pr)
		{
			New->Next=ptr;
			Front=New;
		}
		else
		{
		while(ptr->Next!=NULL && ptr->Next->Pr<=New->Pr)
		{
			ptr=ptr->Next;
		}
		if(ptr->Pr<=New->Pr)
		{
			if(ptr->Next!=NULL)
			{
				New->Next=ptr->Next;
				ptr->Next=New;
			}
			else
			{
				ptr->Next=New;
				Rear=New;
			}
		}
		}
	}
}
	


void Del()
{
	int Value;
	struct Node *temp,*ptr;
	if(Front==NULL && Rear==NULL)
	{
		printf("Underflow\n");
	}
	else if(Front==Rear)
	{	
	Value=Rear->info;
	temp=Rear;
	Front=NULL;
	Rear=NULL;
	free(temp);
	printf("Deleted item is %d\n",Value);
	}
	else
	{
	Value=Rear->info;
	temp=Rear;
	ptr=Front;
	while(ptr->Next->Next!=NULL)
	{
		ptr=ptr->Next;	
	}
	Rear=ptr;
	free(temp);
	printf("Deleted item is %d\n",Value);
	}
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
		int t,t1,Pr;
		case 1:	
		printf("Enter the Number to Enqueue ");
		scanf("%d",&t);
		printf("Enter Priority ");
		scanf("%d",&Pr);
		Insert(t,Pr);
		break;
			
		case 2:
			if(Front==NULL && Rear==NULL)
			{
				printf("Underflow\n");
				break;
			}
			else 
			{
				Del();
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
