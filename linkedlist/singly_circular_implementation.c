#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;
node *head = NULL;

void traverse()
{
    node *temp = head;
    if(temp==NULL)
    {
        printf("empty list");
    }
    do   
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

int main()
{
    head = (node*)malloc(sizeof(node));
    head->data=23;
    head->next = head;

    node *newnode = (node*)malloc(sizeof(node));
    newnode->data=34;
    newnode->next=head;
    head->next=newnode;

    traverse();
}

