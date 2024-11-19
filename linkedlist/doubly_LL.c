#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node node;
node *head = NULL;

node *newnode(int value)
{
    node *temp= (node*)malloc(sizeof(node));
    if(temp==NULL)
        printf("memory is not allocated");
    else
    {
        temp->data = value;
        temp->prev = NULL;
        temp->next = NULL;
    }
    return temp;
}

void insertatbeg(int value)
{
    node *temp= newnode(value);
    if(head==NULL)
        head=temp;
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertatend(int value)
{
    node *temp= newnode(value);
    if(head==NULL)
        head=temp;
    else
    {
        node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        temp->prev=p;
        p->next=temp;
    }
}

void deleteatbeg()
{
    if(head==NULL)
      printf("empty list");
    else
    {
        node *p=head;
        head=p->next;
        head->prev=NULL;
        free(p);
    }         
}

void deleteatend()
{
   if(head==NULL)
        printf("empty list");
    else if(head->next == NULL)
        head=NULL;
    else
    {
        node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->prev->next=NULL;
        free(p);
    } 
}

void display()
{
    if(head==NULL)
        printf("\nempty list");
    else
    {
        node *p=head;
        while(p!=NULL)
        {
            printf("%d->",p->data);
            p=p->next;
        }
    }
}

node *searching(int value)
{
    if(head==NULL)
        printf("empty list");
    else
    {
        node *p=head;
        while(p!=NULL)
        {
            if(p->data==value)
            {
                return p;
            }
            p=p->next;
        }
        return NULL;
    }
}

void insertbefore(int before,int value)
{
    node *curr=searching(before);
    node *p = head;
    if(curr==NULL)
        printf("not found");
    else if(curr==p)
        insertatbeg(value);
    else
    {
        node *temp = newnode(value);
        temp->next=curr;
        temp->prev=curr->prev;
        curr->prev->next=temp;
        curr->prev=temp;
    }

}

void insertafter(int after,int value)
{
    node *curr=searching(after);
    if(curr==NULL)
        printf("not found\n");
    else if(curr->next == NULL)
        insertatend(value);
    else
    {
        node *temp = newnode(value);
        curr->next->prev = temp;
        temp->next=curr->next;
        curr->next=temp;
        temp->prev=curr;
    }
}

void deletebefore(int before)
{
    node *curr=searching(before);
    node *p=head;
    if(head==NULL)
        printf("empty list\n");
    else if(curr==p)
        printf("no data before this\n");
    else if(curr==NULL) 
        printf("not found\n");
    else if(p->next==curr)
        deleteatbeg();
    else
    {
        node *q=curr->prev;
        curr->prev=q->prev;
        q->prev->next=curr;
        free(q);

    }
}

void deleteafter(int after)
{
    node *curr=searching(after);  
    if(head==NULL)
        printf("empty list\n"); 
    else if(curr==NULL) 
        printf("not found\n");
    else if(curr->next==NULL)
        printf("no data before this\n");
    else if(curr->next->next==NULL)
        deleteatend();
    else
    {
        node *p=curr->next;
        curr->next=p->next;
        p->next->prev=curr;
        free(p);
    }  
}
int main()
{
   insertatbeg(10);
   //insertatend(20);
   //insertatend(30);
   //deleteatbeg();
   deleteatend();
   //insertbefore(70,100);
   //insertafter(10,100);
   //deletebefore(10);
   //deleteafter(30);
   display();
}