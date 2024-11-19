#include <stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;
node *head=NULL;

 node *newnode(int val)
{
  node *temp=(node*)malloc(sizeof(node));
  if(temp==NULL)
    printf("Memory not allocated.");
  else
  {
    temp->data=val;
    temp->next=NULL;
  }
  return temp;
}

void insertatbegin(int val)
{
  if(head==NULL)
    head=newnode(val);
  else
  {
    node *temp=newnode(val);
    temp->next=head;
    head=temp;
  }
}

void insertatend(int val)
{
    node *temp=newnode(val);
    if(head==NULL)
      head=temp;
    else
    {
        node *temp1=head;
        while(temp1->next!=NULL)
        {
          temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

node *searching(int val)
{
    if(head==NULL)
      printf("empty list");
    else
    {
      node *temp = head;
      while(temp!=NULL)
      {
        if(temp->data==val)
        {
          return temp;
        }
        temp=temp->next;
      }
      return NULL;
    }
}

void insertafter(int after,int value)
{
    node *curr=searching(after);
    if(curr==NULL)
      printf("\nnot found");
    else
    {
       node *temp = newnode(value);
       temp->next=curr->next;
       curr->next=temp;
    }
}

void insertbefore(int before,int value)
{
    node *curr=searching(before);
    node *p=head;

    if(curr==NULL)
      printf("\nnot found");
    else if(curr==p)
      insertatbegin(value);
    else
    {
      while(p->next!=curr)
      {
        p=p->next;
      }
      node *temp = newnode(value);
      temp->next=curr;
      p->next=temp;
    }
}

void insertatpos(int pos,int value)
{
    node *p=head;
    int i=1;
    while(i<pos-1 && p!=NULL)
    {
      p=p->next;
      i++;
    }
    if(p==NULL)
      printf("not found");
    else
    {
      node *temp=newnode(value);
      temp->next=p->next;
      p->next=temp;
    }
}
void deleteatbegin()
{
  if(head==NULL)
    printf("cannot deleted list is empty");
  else
  {
    node *p=head;
    head=head->next;
    free(p);
  }
}

void deleteatend()
{
  if(head==NULL)
    printf("cannot deleted list is empty");
  else if(head->next==NULL)
    deleteatbegin();
  else
  {
    node *p=head;
    node *q=p->next;
    while(q->next!=NULL)
    {
      p=p->next;
      q=q->next;
    }
    p->next=NULL;
    free(q);    
  }
}


void deleteafter(int value)
{
  node *curr=searching(value);
  if(head==NULL)
    printf("cannot deleted list is empty");
  else if(curr==NULL || curr->next==NULL)
    printf("value not found");
  else
  {
    node *p = curr->next;
    curr->next = p->next;
    free(p);
  } 
}

void deletebefore(int value)
{
  node *curr=searching(value);
  node *p = head;
  if(head==NULL)
    printf("cannot deleted list is empty");
  else if(curr==NULL || curr==p)
    printf("value not found");
  else if(curr==head->next)
    deleteatbegin();
  else
  {
    node *p=head;
    node *q=p->next;
    while(q->next!=curr)
    {
      p=p->next;
      q=q->next;
    }
    p->next=curr;
    free(q);
  }
}

void deleteatpos(int pos)
{
  if(pos==1)
  deleteatbegin();
  else
  {
    node *p=head;
    node *q=p->next;
    int i=2;
    while(q!=NULL)
    {
      if(i==pos)
      {
        p->next=q->next;
        free(q);
        break;
      }
      p=p->next;
      q=q->next;
      i++;
    }
    printf("Position not found\n");
  }
}

void deletingwholenode()
{
  node *p=head;
  while(p!=NULL)
  {
    p = p->next;
    free(head);
    head=p;
  }
}

void reversinglist()
{
  node *prev = NULL;
  node *curr = head;
  while(head!=NULL)
  {
    curr=head->next;
    head->next=prev;
    prev=head;
    head=curr;
  }
  head=prev;
}

void traverse()
{
  node *p=head;
  if(p==NULL)
    printf("empty list");
  else 
  {
    while(p!=NULL)
    {
      printf("%d->",p->data);
      p=p->next;
    }
  }
}

int main()
{
  printf("enter 1 for insert at beg\n2 for insert at end\n3 for delete at beg\n4 for del at end\n5 for traversing\n6 for insert before value\n7 for insert after value\n8 for delete before value\n9 for delete after value\nany number for exit");
  int choice,value,before,after;
  while(1)
  {
    printf("\nenter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 : 
              printf("enter value : ");
              scanf("%d",&value);
              insertatbegin(value);
              break;
      case 2 : 
              printf("enter value : ");
              scanf("%d",&value);
              insertatend(value);
              break;
      case 3 : 
              deleteatbegin();
              break;
      case 4 :
              deleteatend();
              break;
      case 5 : 
              traverse();
              break;
      case 6 : 
              printf("enter value before which u want to insert : ");
              scanf("%d",&before);
              printf("enter value : ");
              scanf("%d",&value);
              insertbefore(before,value);
              break;
      case 7 : 
              printf("enter value after which u want to insert : ");
              scanf("%d",&after);
              printf("enter value : ");
              scanf("%d",&value);
              insertafter(after,value);
              break;
      case 8 : 
              printf("enter value before which u want to delete : ");
              scanf("%d",&before);
              deletebefore(before);
              break;
      case 9 : 
              printf("enter value after which u want to delete : ");
              scanf("%d",&after);
              deleteafter(after);
              break;
      default : 
               printf("wrong choice");
               return 0;
    }
  }
}