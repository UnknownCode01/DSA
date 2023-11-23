#include <stdbool.h>
#include <stdio.h>
bool isBalanced(char exp[])
{
    bool flag = true;
    int count = 0;
    for (int i = 0; exp[i] != '\0'; i++) 
    {
        if (exp[i] == '(') {
            count++;
        }
        else if(exp[i] == ')'){
            count--;
        }
        if (count < 0) {
            flag = false;
            break;
        }
    }
    if (count != 0) {
        flag = false;
    }
    return flag;
}

int main()
{
    char exp1[30];
    printf("Enter string to check if paranthesis is balanced or not\n");
    gets(exp1);
    if (isBalanced(exp1))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
