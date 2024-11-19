#include <stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *left,*right;
  int height;
};

typedef struct Node node;

int max(int a,int b)
{
    return (a>b)?a:b;
}

node *createnode(int value)
{
  node *temp = (node*)malloc(sizeof(node));
  if(temp==NULL)
    printf("memory is not allocated");
  else
  {
    temp->data = value;
    temp->left = temp->right = NULL;
    temp->height = 0;
    return temp;
  }
}

int height(node *p)
{
  if(p==NULL)
    return -1;
  else
    return max(height(p->left),height(p->right)) + 1;
}

int balancefactor(node *q)
{
    if(q==NULL)
        return 0;
    else
        return height(q->left)-height(q->right);
}

node *rightrotate(node *z)
{
    node *y = z->left;
    node *x = y->right;

    y->right = z;
    z->left=x;

    z->height = max(height(z->left),height(z->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1; 

    return y;
}

node *leftrotate(node *x)
{
    node *y = x->right;
    node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;

    return y;
}

node *insert(node *root,int val)
{
  if(root==NULL)
    return createnode(val);
  else if(val > root->data)
    root->right = insert(root->right,val);
  else if(val < root->data)
    root->left = insert(root->left,val);
  else if (val==root->data)
    printf("Value already exists\n"); 
  else
    return root;


  root->height = max(height(root->left),height(root->right)) + 1;
  int bf = balancefactor(root);

  // left left case 
  if(bf > 1 && val < root->left->data)
    return rightrotate(root);

  // right right case
  else if(bf < -1 && val > root->right->data)
    return leftrotate(root);

  // left right rotation
  else if(bf > 1 && val > root->left->data)
  {
    root->left = leftrotate(root->left);
    return rightrotate(root);
  }

  // right left rotation
  else if(bf < -1 && val < root->right->data)
  {
    root->right = rightrotate(root->right);  
    return leftrotate(root);
  }
  else
    return root;

}

node *successor(node *p)
{
  while(p->left != NULL && p!=NULL)
  {
    p = p->left;
  }
  return p;
}

node *delete(node *root,int val)
{
  if(root==NULL)
    return NULL;
  else if(val > root->data)
    root->right = delete(root->right,val);
  else if(val < root->data)
    root->left = delete(root->left,val);
  else if(root->data==val)
  {
    if(root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    else if(root->left == NULL)
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
     else if(root->right == NULL)
    {
      node *temp = root->left;
      free(root);
      return temp;
    }
    else
    {
      node *succ = successor(root->right);
      root->data = succ->data;
      root->right = delete(root->right, succ->data);
    }
  }
  else
    return root;
    
  
  root->height = max(height(root->left),height(root->right)) + 1;
  int bf = balancefactor(root);

  // left left case 
  if(bf > 1 && balancefactor(root->left) >= 0)
    return rightrotate(root);

  // right right case
  else if(bf < -1 && balancefactor(root->right) <= 0)
    return leftrotate(root);

  // left right rotation
  else if(bf > 1 && balancefactor(root->left) < 0)
  {
    root->left = leftrotate(root->left);
    return rightrotate(root);
  }
 
  // right left rotation
  else if(bf < -1 && balancefactor(root->left) > 0)
  {
    root->right = rightrotate(root->right);  
    return leftrotate(root);
  }
  else
    return root;
  
}

void preorder(node *root)
{
  if(root==NULL)
    return;
  else
  {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}


int main()
{
    node *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    preorder(root);
    root = delete(root,10);
    printf("\n");
    preorder(root);
}