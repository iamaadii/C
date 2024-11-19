#include <stdio.h>
#define max 3
int a[max];
int top = -1;

void push(int value)
{
    if(top==max-1)
    printf("overflow");
    else
    {
        top++;
        a[top]=value;
    }
}

void pop()
{
    if(top==-1)
    printf("underflow");
    else
    {
       int value= a[top];
       top--;
       printf("%d popped out from stack\n",value);
    }
}

void print()
{
    if(top==-1)
    printf("underflow");
    else
    {
        for(int i=top;i>=0;i--)
        printf("%d ",a[i]);
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    pop();
    push(30);
    push(20);
    push(10);
    pop();
    pop();
    pop();
}
