// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#define size 100
#include<math.h>

void evaluation(char postfix[])
{
    char stack[size];
    int top = -1;
    int result;
    
    for(int i = 0;i<strlen(postfix);i++)
    {
        char s = postfix[i];
        if(s>='0' && s<='9')
            stack[++top] = s-'0';
        else
        {
            int a = stack[top--];
            int b = stack[top--];
            
            switch(s)
            {
                case '+' :
                            result = b+a;
                            break;
                case '-' :
                            result = b-a;
                            break;
                case '*' :
                            result = b*a;
                            break;
                case '/' :  
                            if(a==0)
                            {
                                printf("cannot divide");
                                return ;
                            }
                            result = b/a;
                            break;
                case '^' :  
                            result = pow(b,a);
                            break;
                default :
                            printf("invalid operator ");
                            return ;
            }
            stack[++top] = result;
        }
    }
    printf("result : %d",stack[top]);
}
int main() {
    char postfix[size];
    printf("Enter postfix expression : ");
    scanf("%s",postfix);
    evaluation(postfix);
}