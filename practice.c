/** binary search tree insertion operation with user input */

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left,*right; 
};

typedef struct Node node;

node *createnode(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    if(temp==NULL)
        printf("memory not allocated");
    else if(data==-1)
        return NULL; 
    else
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
}

node *insert(node *root,int value)
{
    if(root==NULL)
    {
        return createnode(value);
    }
    else if(root->data < value)
    {
        root->right=insert(root->right,value);
    }
    else if(root->data > value)
    {
        root->left=insert(root->left,value);
    }
    else
    {
        printf("already exist");
    }
    return root;
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return; 
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    int choice,value,x;
    node *root = NULL;

    printf("\n1.for insertion\n2.for printing\nAny number for exit\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   printf("Enter node : ");
                   scanf("%d",&x);
                   root = insert(root,x);
                   break;
            case 2 :
                    inorder(root);
                    break;
            default :
                     printf("wrong choice");
                     return 0;
        }
    }
}