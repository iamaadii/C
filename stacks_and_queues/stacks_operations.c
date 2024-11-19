#include <stdio.h>
#define max 6
int a[max];
int top = -1;

void push(int value)
{
    if(top == max-1)
        printf("overflow");
    else
    {
        top++;
        a[top]=value;
    }
}

void pop()
{
    if(top == -1)
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
    if(top == -1)
        printf("underflow");
    else
    {
        for(int i=top;i>=0;i--)
            printf("%d\n",a[i]);
    }
}

void peek()
{
    if(top==-1)
        printf("underflow");
    else
        printf("peek element : %d\n",a[top]);
}

void searching(int element)
{
    int i;
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        for (i = top; i >= 0; i--)
        {
            if (a[i] == element)
            {
                printf("%d is present at index %d\n", element, i);
                break;
            }
        }
        if(i<0)
            printf("not found");
    }
}

int main()
{
    int choice,data,key;
    printf("\nenter 1 for push");
    printf("\nenter 2 for pop");
    printf("\nenter 3 for print");
    printf("\nenter 4 for peek");
    printf("\nenter 5 for searching");
    printf("\nenter any number for exit");
    while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   printf("enter data : ");
                   scanf("%d",&data   );
                   push(data);
                   break;
            case 2 : pop();
                     break;
            case 3 : print();
                     break;
            case 4 : peek();
                     break;
            case 5 :
                     printf("enter element which you want to search : ");
                     scanf("%d",&key);
                     searching(key);
                     break;
            default : printf("wrong choice ");
                      return 0;
         }
    }
}
