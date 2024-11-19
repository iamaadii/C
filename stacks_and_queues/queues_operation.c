#include <stdio.h>
#define size 3
int queue[size];
int rear = -1;
int front = -1;;

void enqueue(int value)
{
    if(rear==size-1)
        printf("full\n");
   
    else if(rear==-1 && front==-1)
    {
        ++front;
        queue[++rear]=value;
    }
   
    else
        queue[++rear]=value;
}

void dequeue()
{
    if(rear==-1 && front==-1)
        printf("empty\n");
   
    else if(rear==front)
    {
        printf("%d deleted\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else
        printf("%d deleted\n",queue[front++]);
}

void display()
{
    if(rear==-1 && front==-1)
        printf("empty\n");
   
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
}

void peek()
{
    if(rear==-1&&front==-1)
        printf("\nempty");   
    else
        printf("peek = %d\n",queue[rear]);
}

void searching(int element)
{
    if(rear==-1&&front==-1)
        printf("queue is empty\n");
    else
    {
        int found = 0;
        for(int i = front; i <= rear; i++)
        {
            if (queue[i] == element)
            {
                printf("%d is present at index %d\n", element, i);
                found = 1;
                break;
            }
        }
        if(found ==0)
            printf("not found");
    }
}

int main()
{
    int choice,data,key;
    printf("\nenter 1 for ennqueue");
    printf("\nenter 2 for dequeue");
    printf("\nenter 3 for print");
    printf("\nenter 4 for peek");
    printf("\nenter 5 for searching");
    printf("\nEnter any other number for exit");
    do
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    printf("enter data : ");
                    scanf("%d",&data   );
                    enqueue(data);
                    break;
            case 2 : dequeue();
                     break;
            case 3 : display();
                     break;
            case 4 : peek();
                     break;
            case 5 :
                     printf("enter searching element : ");
                     scanf("%d",&key);
                     searching(key);
                     break;
            default :
                    printf("wrong choice\n");
                    return 0;
         }
    }while(choice<6);
}
