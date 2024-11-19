// Implementation of binary tree without user input...

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node *newnode()
{
    int x;
    node *temp = (node*)malloc(sizeof(node));
    printf("enter data (-1 for no node) : ");
    scanf("%d",&x); 

    if(x==-1)
    {
        return NULL;
    }
    temp->data = x;

    printf("enter left child of %d\n",x);
    temp->left = newnode();

    printf("enter right child of %d\n",x);
    temp->right = newnode();
    
    return temp;
}

void inorder(node *p)
{
    if (p == NULL)
    {
        return ;
    }
    inorder(p->left);
    printf("%d ",p->data);
    inorder(p->right);
}

void preorder(node *p)
{
    if(p == NULL)
    {
        return;
    }
    printf("%d ",p->data);
    preorder(p->left);
    preorder(p->right);
}

void postorder(node *p)
{
    if(p == NULL)
    {
        return;
    }
    postorder(p->left);
    postorder(p->right);
    printf("%d ",p->data);
}

int height(node *root)
{
    if(root==NULL)
      return -1;
    else 
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}


void levelorder(node *p,int level)
{
    if(p==NULL)
       return;
    if(level==0)
       printf("%d ",p->data);
    else if(level>0)
    {
        levelorder(p->left,level-1);
        levelorder(p->right,level-1);
    }    
}

void main()
{
    node *head = newnode();
    printf("inorder is : ");
    inorder(head);

    printf("\npreorder is : ");
    preorder(head);

    printf("\npostorder is : ");
    postorder(head);

}