#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* insertion(struct Node *Head,int nu,int pos)
{
	struct Node *New=(struct Node *)malloc(sizeof(struct Node));
	struct Node *PTR;
	PTR=Head;
	if(pos==1)
	{
		New->data=nu;
		New->next=Head;
		while(PTR->next!=Head)
		PTR=PTR->next;
		PTR->next=New;
		Head=New;
		return Head;	
	}
	else
	{
		int count=1;
		while(count!=pos-1){
			PTR=PTR->next;
			count++;
		}
		New->next=PTR->next;
		PTR->next=New;
		New->data=nu;
		return Head;	
	}	
}
struct Node* deletion(struct Node *Head,int pos)
{
	struct Node *PTR;
	PTR=Head;
	int count=1;
	if(pos==1){
		while(PTR->next!=Head)
		PTR=PTR->next;
		PTR->next=Head->next;
		Head=Head->next;
		return Head;
	}
	else{
	while(count!=pos-1)
	{
		PTR=PTR->next;
		count++;
	}	
	PTR->next=(PTR->next)->next;
	return Head;
	}
}
void display(struct Node *Head){
	struct Node *PTR;
	PTR=Head;
	while(PTR->next!=Head){
	printf("%d ",PTR->data);
	PTR=PTR->next;
	}
	printf("%d",PTR->data);
}

int main (void){
	int c,nu,pos;
struct Node *Head;
struct Node *New;
struct Node *ptr;
char choice;
Head=NULL;
New=(struct Node*)malloc(sizeof(struct Node));
printf("Enter a value: ");
scanf("%d",&New->data);
fflush(stdin);
New->next=NULL;
Head=New;
ptr=Head;
printf("\nDo you want to add another Node?\n\n(Y/N): ");
scanf("%c",&choice);
while(choice=='Y' || choice =='y'){
New=(struct Node*)malloc(sizeof(struct Node));
printf("Enter a value: ");
scanf("%d",&New->data);
fflush(stdin);
New->next=NULL;
ptr->next=New;
ptr=ptr->next;
printf("\nDo you want to add another Node?\n\n(Y/N): ");
scanf("%c",&choice);
}

ptr->next=Head;
ptr=Head;
printf("\nShowing circular linked list\n");
while(ptr->next!=Head){
	printf("%d ",ptr->data);
	ptr=ptr->next;
}
printf("%d ",ptr->data);
printf("\n1. Inserton\t2. Deletion");
printf("\nEnter which one to perform ");
scanf("%d",&c);
if(c==1)
{
printf("\nEnter the number to insert ");
scanf("%d",&nu);
printf("Enter the position ");
scanf("%d",&pos);
Head=insertion(Head,nu,pos);	
printf("\nDisplaying Linked List After Insertion\n");
display(Head);
}
else if(c==2)
{
printf("Enter the index of the number you want to delete ");
scanf("%d",&pos);
Head=deletion(Head,pos);	
printf("\nDisplaying Linked List After Deletion\n");
display(Head);
}
else
printf("Invalid Input.");
return 0;
}
