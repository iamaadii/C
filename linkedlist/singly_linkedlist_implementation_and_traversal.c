#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;

void traversal()
{
    node *temp = head;
    if(temp==NULL)
    printf("empty linked list");

    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    head = (node*)malloc(sizeof(node));
    node *newnode1 = (node*)malloc(sizeof(node));
    node *newnode2 = (node*)malloc(sizeof(node));

    head->data=10;
    head->next=newnode1;

    newnode1->data=20;
    newnode1->next=newnode2;

    newnode2->data=30;
    newnode2->next=NULL;

    traversal();
}


//method 2

// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };
// typedef struct Node node;
//
// void traversal(node *temp)
// {
//     if(temp==NULL)
//     printf("empty linked list");

//     else
//     {
//         while(temp!=NULL)
//         {
//             printf("%d->",temp->data);
//             temp=temp->next;
//         }
//     }
// }
//
// int main()
// {
//     node *head = NULL;
//     head = (node*)malloc(sizeof(node)); //first node created
//     head->data=10;
//     head->next=NULL;

//     node *newnode1 = (node*)malloc(sizeof(node)); //second node created
//     newnode1->data=20;
//     newnode1->next=NULL;
//     head->next=newnode1;

//     node *newnode2 = (node*)malloc(sizeof(node)); //third node created
//     newnode2->data=30;
//     newnode2->next=NULL;
//     newnode1->next=newnode2;

//     traversal(head);
// }



//method 3

// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };
// typedef struct Node node;

// void traversal(node *temp)
// {
//     if(temp==NULL)
//     printf("empty linked list");
//
//     else
//     {
//         while(temp!=NULL)
//         {
//             printf("%d->",temp->data);
//             temp=temp->next;
//         }
//     }
// }
//
// int main()
// {
//     node *head = NULL;
//     head = (node*)malloc(sizeof(node)); //first node created
//     head->data=10;
//     head->next=NULL;

//     node *newnode1 = (node*)malloc(sizeof(node)); //second node created
//     newnode1->data=20;
//     newnode1->next=NULL;
//     head->next=newnode1;

//     newnode1 = (node*)malloc(sizeof(node)); //third node created
//     newnode1->data=30;
//     newnode1->next=NULL;
//     head->next->next=newnode1;
//     traversal(head);
// }
