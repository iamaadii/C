#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;
node *head = NULL;

node *newnode(int value)
{
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
      printf("memory not allocated");
    else
    {
        temp->data=value;
        temp->next=temp;
        temp->prev=temp;
    }
    return temp;
}

void insertatbeg(int value)
{
    node *temp = newnode(value);
    if(head==NULL)
       head=temp;
    else
    {
        node *p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        temp->next=head;
        temp->prev=p;
        p->next=temp;
        head->prev=temp;
        head=temp;
    }
}

void insertatend(int value)
{
    node *temp = newnode(value);
    if(head==NULL)
       head=temp;
    else
    {
        node *p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        temp->prev=p;
        temp->next=head;
        p->next = temp;
        head->prev=temp;
    }
}

void deleteatbeg()
{
    node *p=head;
    if(head==NULL)
        printf("empty list");
    else if(p->next==p)
        head = NULL;
    else
    {
        head = head->next;
        head->prev=p->prev;
        p->prev->next=head;
        free(p);
    }
}

void deleteatend()
{
    node *p=head;
    if(head==NULL)
        printf("empty list");
    else if(p->next==p)
        deleteatbeg();
    else
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        p->prev->next=head;
        head->prev=p->prev;
        free(p);
    }
}

void traverse()
{
    node *p=head;
    if(p==NULL)
        printf("empty list");
    else
    {
        do
        {
            printf("%d->",p->data);
            p=p->next;
        } while (p!=head);    
    }
}

int main()
{
    insertatbeg(10);
    //insertatbeg(20);
    //insertatend(30);
    //insertatend(40);
    //deleteatbeg();
    deleteatend();
    traverse();
}