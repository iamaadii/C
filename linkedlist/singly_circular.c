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

void insertatbeg(int value)
{
    if(head==NULL)
        head=newnode(value);
    else
    {
        node *p = head;
        while(p->next!=head)
        {
            p=p->next;
        }
        node *temp=newnode(value);
        temp->next=head;
        head=temp;
        p->next=head;
    }
}

void insertatend(int value)
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

void deleteatbeg()
{
    node *p=head;
    node *q=head;

    if(head==NULL)
       printf("empty list");
    else if(p->next==head)
        head=NULL;
    else
    {
        while(q->next!=head)
        {
            q=q->next;
        }
        q->next = p->next;
        head=p->next;
        free(p);
    }
}

void deleteatend()
{
    node *p=head;
    node *q=p->next;

    if(head==NULL)
        printf("empty list");
    else if(head->next==head)
       deleteatbeg();
    else
    {
        while(q->next!=head)
        {
            p=p->next;
            q=q->next;
        }
        p->next=head;
        free(q);
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

node *searching(int value)
{
    node *p = head;
    if(head==NULL)
        printf("empty list");
    else
    {   do 
        {
            if (p->data == value) 
            {
                return p;
            }
            p = p->next;
        } while (p != head);
        return NULL;
    }
}

void insertbefore(int before,int value)
{
    node *curr = searching(before);
    node *p = head;
    
    if(head==NULL)
    printf("empty list");
    
    else if(curr==p)
    insertatbeg(value);
    
    else if(curr==NULL)
    printf("not found");
    
    else
    {
        while(p->next!=curr)
        {
            p=p->next;
        }
        node *temp=newnode(value);
        temp->next=p->next;
        p->next=temp;
    }
}

int main()
{
    insertatbeg(3);
    //insertatbeg(20);
    //insertatbeg(30);
    insertatend(28);
    insertatend(1);
    insertatend(4);
    //searching(10);
    //insertbefore(40,100);
    //deleteatbeg();
    //deleteatend();
    traversal();
}