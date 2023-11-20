#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* insertion(struct Node* Head,int nu,int pos,int count){
	struct Node *New=(struct Node *)malloc(sizeof(struct Node));
	struct Node *PTR;
	PTR=Head;
	int count1=1;
	if(pos==1){
		New->data=nu;
		New->prev=NULL;
		New->next=PTR;
		PTR->prev=New;
		Head=New;
		return Head;
	}
	else if(pos==count){
		New->next=NULL;
		New->data=nu;
		while(PTR->next!=NULL){
			PTR=PTR->next;
		}
		PTR->next=New;
		New->prev=PTR;
		return Head;
	}
	else{
		New->data=nu;
		while(count1!=pos){
			count1++;
			PTR=PTR->next;
		}
		New->next=PTR;
		PTR=PTR->prev;
		PTR->next=New;
		New->prev=PTR;
		((PTR->next)->next)->prev=New;
		return Head;
	}
}
struct Node * deletion(struct Node*Head,int pos,int count){
	struct Node *PTR;
	PTR=Head;
	int count1=1;
	if(pos==1){
		Head=Head->next;
		Head->prev=NULL;
		return Head;
	}
	else if(pos==count){
		while(count1!=count){
			PTR=PTR->next;
			count1++;
		}
		PTR=PTR->prev;
		PTR->next=NULL;
		return Head;
	}
	else{
		while(count1!=pos){
			PTR=PTR->next;
			count1++;
		}
		PTR=PTR->prev;
		PTR->next=(PTR->next)->next;
		(PTR->next)->prev=PTR;
		return Head;
	}
}
void display(struct Node* Head){
	struct Node * PTR;
	PTR=Head;
	while(PTR!=NULL){
	printf("%d ",PTR->data);
	PTR=PTR->next;
	}
	}
int main(){
	struct Node *Head;
	struct Node *New;
	struct Node *PTR;
	char choice;
	int nu,pos,c,count=0;	
	Head=NULL;
	
	New=(struct Node *)malloc(sizeof(struct Node));
	printf("Enter a value: ");
	scanf("%d",&New->data);
	Head=New;
	PTR=Head;
	New->next=NULL;
	New->prev=NULL;

	printf("\nDo you want to add another Node?\n\n(Y/N): ");
	fflush(stdin);	
	scanf("%c",&choice);
	while(choice == 'Y' || choice == 'y')
	{
		New=(struct Node *)malloc(sizeof(struct Node));
		printf("Enter a value: ");
		scanf("%d",&New->data);
		New->next=NULL;
		New->prev=PTR;
		PTR->next=New;
		PTR=PTR->next;
		printf("\nDo you want to add another Node?\n\n(Y/N): ");
		fflush(stdin);	
		scanf("%c",&choice);
	}
	display(Head);
	PTR=Head;
	while(PTR!=NULL){
	count++;
	PTR=PTR->next;
	}
	printf("\nSelect one \n1. Insertion\t2. Deletion\n");
	scanf("%d",&c);
	if(c==1){
		printf("1. At begining\t2. At end\t3. At a pos\n");
		scanf("%d",&c);
		if(c==1)
		pos=1;
		else if(c==2)
		pos=count;
		else if(c==3){
			printf("Enter the position ");
			scanf("%d",&pos);
		}
		else{
		printf("Invalid Input");
		return 0;}
		printf("Enter the number ");
		scanf("%d",&nu);
		Head=insertion(Head,nu,pos,count);
	}
	else if(c==2){
		printf("1. At begining\t2. At end\t3. At a pos\n");
		scanf("%d",&c);
		if(c==1)
		pos=1;
		else if(c==2)
		pos=count;
		else if(c==3){
			printf("Enter the position ");
			scanf("%d",&pos);
		}
		else{
		printf("Invalid Input");
		return 0;}
		Head=deletion(Head,pos,count);
	}
	else
	printf("Invalid Input");
	display(Head);
	
	return 0;
}
