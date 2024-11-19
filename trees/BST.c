// Binary search tree all operations like insertion,deletion,searching,traversing with user input...

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
    else
    {
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
}

node *insert(node *root,int value)
{
    node *prev=NULL;
    while(root!=NULL)  // it will run till root not becomes NULL
    {
        prev=root;  
        if(root->data==value)
        {
            printf("already exist\n");
            return NULL;
        }
        else if(value>root->data)
            root=root->right;
        else
            root=root->left;
    }
    if(value<prev->data)
        prev->left=createnode(value);
    else
        prev->right=createnode(value);
}

void inorder(node *root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

node *search(node *root,int target)
{
    if(root==NULL)
    {
        printf("not found\n");
        return NULL;
    }
    else if(root->data==target)
    {
        printf("found\n");
        return root;
    }
    else if(root->data>target)
        search(root->left,target);
    else
        search(root->right,target);
}

node *successor(node *curr)
{
    curr=curr->right;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

node *delete(node *root,int key)
{
    if(root==NULL)
        return NULL;
    else if(key<root->data)
        root->left=delete(root->left,key);
    else if(key>root->data)
        root->right=delete(root->right,key);
    else
    {
        if(root->left == NULL && root->right==NULL)
        { 
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL) 
        {
            node *temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            node *succ = successor(root);
            root->data = succ->data;
            root->right = delete(root->right,succ->data);
        }
    }
}

int main()
{
    // int choice, value;
    // printf("Enter root node : ");
    // scanf("%d",&value);
    // node *root = createnode(value);

    // printf("\n1.for insertion\n2.for inorder traversing\n3.for searching key node\n4.for deletion\nAny number for exit\n");
    // while(1)
    // {
    //     printf("\nEnter your choice : ");
    //     scanf("%d",&choice);
    //     switch(choice)
    //     {
    //         case 1:
    //             printf("Enter value of node : ");
    //             scanf("%d",&value);
    //             insert(root,value);
    //             break;
    //         case 2:
    //             inorder(root);
    //             printf("\n");
    //             break;
    //         case 3:
    //             printf("Enter searching element : ");
    //             scanf("%d",&value); 
    //             search(root,value);
    //             break;
        //     case 4:
        //         printf("Enter deleting element : ");
        //         scanf("%d",&value); 
        //         delete(root,value);
        //         break;    
        //     default :
        //         printf("wrong choice");
        //         exit(1);
        // }
   // }

  node *root = createnode(8);
  insert(root, 3);
  insert(root, 1);
  insert(root, 6);
  insert(root, 10);
  inorder(root);
  delete(root, 8);
  printf("\n");
  inorder(root);
}





