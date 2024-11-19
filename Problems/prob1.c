// 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;
node *head = NULL;

node *newnode(int value)
{
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
        printf("memory is not allocated");
    else
    {
        temp->data=value;
        temp->next=temp;
    }
    return temp;
}

void insert(int value)
{
    if(head==NULL)
        head=newnode(value);
    else
    {
        node *p=head;
        //node *q=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        node *temp=newnode(value);
        p->next=temp;
        temp->next=head;
    }
}

void traversal()
{
    node *temp = head;
    if(temp==NULL)
        printf("empty list");
    else
    {
        do   
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}

void add()
{
    int even=0,odd=0;
    node *temp = head;
    if(temp==NULL)
        printf("empty list");
    else
    {
        do   
        {
            int a = temp->data;
            if(a%2 == 0)
                even +=a;
            else
                odd +=a;
            temp=temp->next;
        }while(temp!=head);

        printf("\neven = %d",even);
        printf("\nodd = %d",odd);
    }
}

int main()
{
    int n,key;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter data : ");
        scanf("%d",&key);
        insert(key);
    }
    traversal();
    add();
}