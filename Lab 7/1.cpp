#include <stdio.h>   

int stack[100],i,j,choice=0,n,top=-1;  
void push();  
void pop();  
void show();  
int main()  
{  
    printf("Enter the Number of Elements in the Stack : ");   
    scanf("%d",&n);  
    
    printf("****STACK Operations using Array****");  
    printf("\n----------------------------------------------\n"); 

    while(choice != 4)  
    {  
        printf("Choose from below Options ...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your Choice : \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                show();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting ...");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter Valid Choice : ");  
            }   
        };  
    } 
	return 0; 
}   

void push ()  
{  
    int val;      
    if (top == n-1 )   
    printf("\n OVERFLOW");   
    else   
    {  
    	top++;
        printf("Enter the Value ");  
        scanf("%d",&val);          
        stack[top] = val;   
    }   
}   
  
void pop ()   
{   
    if(top == -1)   
    printf("UNDERFLOW");  
    else  
    top = top -1;   
}   
void show()  
{  
    for (i=top;i>=0;i--)  
    {  
        printf("%d ",stack[i]);  
    }  
    if(top == -1)   
    {  
        printf("Stack is Empty.");  
    }  
}
