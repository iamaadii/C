#include<stdio.h>
#include<stdlib.h>

int vertex=4;

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

struct List
{
    node *head;
};
typedef struct List list;


node *createnode(int x)
{
    node *temp = (node*)malloc(sizeof(node));
    if(temp==NULL)
       printf("Memory not allocated");
    else
    {
        temp->data = x;
        temp->next = NULL;
        return temp;
    }
}

// for undirected edges
void addedge(list *adj[vertex],int s,int d)
{
    node *src = createnode(d);
    src->next = adj[s]->head;
    adj[s]->head = src;

    src = createnode(s);
    src->next = adj[d]->head;
    adj[d]->head = src;
}

//for printing adjacency list
void print(list *adj[vertex])
{
    for(int i=0;i<vertex;i++)
    {
        printf("%d--->",i);
        node *p = adj[i]->head;
        while(p!=NULL)
        {
            printf("%d->",p->data);
            p=p->next;
        }
        printf("NULL");
        printf("\n");
    }
}

int main()
{
    // int choice,s,d;
    // printf("enter number of vertex : ");
    // scanf("%d",&vertex);
    list *adj[vertex];

    for(int i=0;i<vertex;i++)
    {
        adj[i] = (list*)malloc(sizeof(list));
        adj[i]->head = NULL;
    }

    // printf("1.for adding undirected edge\n2.for printing list");
    // do
    // {
    //     printf("\nenter your choice : ");
    //     scanf("%d",&choice);
    //     switch(choice)
    //     {
    //         case 1:
    //                 printf("enter source and destination : ");
    //                 scanf("%d %d",&s,&d);
    //                 addedge(adj,s,d);
    //                 break;
    //         case 2:
    //                print(adj);
    //                 break;
    //         default:
    //                 printf("wrong choice");
    //                 return 0;
    //     }
    // } while(choice<3);
    
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,2,3);
    print(adj);

    free(adj);
}