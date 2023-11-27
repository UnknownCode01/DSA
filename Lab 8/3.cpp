#include<stdio.h>

	int Queue[5];
	int Front=-1;int Rear=-1;

void CQINSERT(int size)
{
	if(Front==0 && Rear==size-1)
	{
		printf("OVERFLOW\n");
		return ;
	}
	else if(Front==Rear+1)
	{
		printf("OVERFLOW\n");
		return ;
	}
	else if(Rear==-1 && Front==-1)
	{
		Front=0;Rear=0;
	}
	else
	Rear=(Rear+1)%size;
	printf("Enter the number to be inserted ");
	int Item;
	scanf("%d",&Item);
	Queue[Rear]=Item;
}

void CQDELETE(int size)
{
	int Value;
	if(Front==-1 && Rear==-1)
	{
		printf("UNDERFLOW\n");
		return ;
	}
	else if(Front==Rear){
		Value=Queue[Front];
		Front=Rear=-1;
	}
	else
	{
		Value=Queue[Front];
		Front=(Front+1)%size;
	}
	printf("Deleted item is %d\n",Value);	
}

void TRAVERSAL(int size)
{
	printf("Displaying Queue Elements\n");
	for(int i=Front;i!=Rear;i=(i+1)%size)
	printf("%d ",Queue[i]);
	printf("%d",Queue[Rear]);
	printf("\n");
}

void PEEK()
{
	if(Front==-1)
	printf("No elements\n");
	else
	printf("%d\n",Queue[Front]);
	
}

void IsEmpty()
{
	if(Front==Rear==-1)
	printf("The Queue is Empty\n");
	else
	printf("The Queue is not Empty\n");
}

void IsFull(int size)
{
	if(Rear==size-1 && Front==0)
	printf("The Queue is Full\n");
	else if(Rear+1==Front)
	printf("The Queue is Full\n");
	else
	printf("The Queue is not Full\n");
}

void choose(int c)
{
	switch(c)
	{
		case 1:			
			CQINSERT(5);
			break;
		case 2:
			CQDELETE(5);
			break;
		case 3:
			PEEK();
			break;
		case 4:
			TRAVERSAL(5);
			break;
		case 5:
			IsEmpty();
			break;
		case 6:
			IsFull(5);
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
