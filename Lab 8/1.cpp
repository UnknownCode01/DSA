#include<stdio.h>

	int Queue[20];
	int Front=-1;int Rear=-1;

void ENQUEUE(int Maxsize)
{
	if(Rear==Maxsize)
	{
		printf("OVERFLOW");
		return ;
	}
	else if(Rear==-1 && Front==-1)
	{
		Front=0;Rear=0;
	}
	else
	Rear++;
	int t;
	printf("Enter Number to Enqueue ");
	scanf("%d",&t);
	Queue[Rear]=t;
}

int DEQUEUE()
{
	int Value;
	if(Front==-1 && Rear==-1)
	{
		printf("UNDERFLOW");
		return (0);
	}
	if(Front==Rear){
		Value=Queue[Front];
		Front=Rear=-1;
	}
	else
	{
		Value=Queue[Front];
		Front++;
	}
	printf("Deleted item is %d\n",Value);	
}

void TRAVERSAL()
{
	printf("Displaying Queue Elements\n");
	for(int i=Front;i<=Rear;i++)
	printf("%d ",Queue[i]);
	printf("\n");
}

void PEEK()
{
	if(Front==-1)
	printf("No elements");
	else
	printf("First element is %d\n",Queue[Front]);
	
}

void IsFull(int Maxsize)
{
	if(Rear==Maxsize)
	{
		printf("Full\n");
		return ;
	}
	else
	printf("Not Full\n");	
	
}

void IsEmpty()
{
	if(Front==-1 && Rear==-1)
	{
		printf("Queue is Empty\n");
	}
	else
	printf("Queue is not Empty\n");
	
}

void choose(int c)
{
	switch(c)
	{
		case 1:			
			ENQUEUE(19);
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
		case 6:
			IsFull(19);
			break;
		default :
			printf("Incorrect Option\n");
			break;				
	}	
	
}
int main()
{
	int c;
	printf("Select from below options\n");
	printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display elements\n5.IsEmpty\n6.IsFull\n7.Exit\n\n");
	while(1){
	printf("\nOption : ");
	scanf("%d",&c);
	if(c==7)
	break;
	choose(c);	
	}
	
	return 0;
}
