/* Binary tree implementation with user input and operations like insertion,traversal,searching,height of node, depth od tree, diameter of node , maximum node , minimum node */

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left,*right;
};

typedef struct Node node;

node *createnode(int x)
{
    node *temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
       printf("memory not allocated");
    else
    {
        temp->data = x;
        temp->left=NULL;
        temp->right = NULL;
        return temp;
    }
}

node *search(node *root,int target)
{
    if(root!=NULL)
    {
        if(root->data == target)
        {
            return root;
        }

        node *left = search(root->left,target);
        if(left != NULL)
        {
            return left;
        }
        
        node *right = search(root->right,target);
        if(right != NULL)
        {
            return right;
        }
    }
    else
        return NULL;
}

void insertatleft(node *root,int parent,int leftchild)
{
    node *parentnode = search(root,parent);
    if(parentnode != NULL)
        parentnode->left = createnode(leftchild);
    else
        printf("parent node not found\n");
}

void insertatright(node *root,int parent,int rightchild)
{
    node *parentnode = search(root,parent);
    if(parentnode!=NULL)
    {
        parentnode->right=createnode(rightchild);
    }
    else
        printf("parent not found\n");
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int height(node *root)
{
    if(root==NULL)
       return -1;
    else
    {
       int hleft=height(root->left);
       int hright=height(root->right);
       return (hleft>hright)?hleft+1:hright+1;
    }
}

int heightofnode(node *root,int value)
{
    node *temp=search(root,value);
    if(temp!=NULL)
    {
        int h= height(temp);
    }
}

int diameter(node *root)
{
    if(root==NULL)
      return -1;
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);
        int dia = lheight+rheight+2;
        return dia;
    }
}

int diameterofnode(node *root,int val)
{
    node *temp=search(root,val);
    if(temp!=NULL)
    {
        int d = diameter(temp);
    }
}

int max(int a,int b, int c)
{
    if(a>=b && a>=c)
        return a;
    else if(b>=a && b>=c)
        return b;
    else
        return c;
}

int min(int a,int b,int c)
{
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

int greaternode(node *root)
{
    if(root==NULL)
        return -1;
    else
    {
        int lmax=greaternode(root->left);
        int rmax=greaternode(root->right);
        return max(root->data,lmax,rmax);
    }
}

int smallernode(node *root)
{
    if(root==NULL)
        return __INT_MAX__;
    else
    {
        int lmin=smallernode(root->left);
        int rmin=smallernode(root->right);
        return min(root->data,lmin,rmin);
    }
}

int main()
{
    int choice, value, parent, leftchild, rightchild;
    printf("Enter root node : ");
    scanf("%d",&value);
    node *root = createnode(value);

    printf("\n1.for inserting left child\n2.for inserting right child\n3.for Inorder traversal\n4.for height of any node\n5.for diameter of any node\n6.for depth of the tree\n7.for min element of tree\n6.for max element in tree\nAny other number for exit \n");

    while (1) 
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the parent node : ");
                scanf("%d", &parent);
                printf("Enter the left child(enter -1 for no node): ");
                scanf("%d", &leftchild);
                insertatleft(root, parent, leftchild);
                break;
            case 2:
                printf("Enter the parent node : ");
                scanf("%d", &parent);
                printf("Enter the right child(enter -1 for no node): ");
                scanf("%d", &rightchild);
                insertatright(root, parent, rightchild);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                printf("enter value of node :  ");
                scanf("%d",&value);
                printf("height : %d",heightofnode(root,value));
                break;
            case 5:
                printf("enter value of node :  ");
                scanf("%d",&value);
                printf("diameter : %d",diameterofnode(root,value));
                break;
            case 6:
                printf("depth of tree : %d",height(root));
                break;
            case 7:
                printf("minimum element in tree : %d",smallernode(root));
                break;
            case 8:
                printf("maximum element in tree : %d",greaternode(root));
                break;
            default:
                printf("Invalid choice\n");
                exit(1);
        }
    }
}