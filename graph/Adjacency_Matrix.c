#include <stdio.h>
int max;

// for adding uni-directional edge
void dirinsert(int adj[max][max],int s,int d)
{
  if((s>=0 && s<max) && (d>=0 && d<max))
    adj[s][d] = 1;
  else
    printf("wrong vertex");
}

// for adding undirected or by-directional edge
void undirinsert(int adj[max][max],int s,int d)
{
  if((s>=0 && s<max) && (d>=0 && d<max))
  {
    adj[s][d] = 1;
    adj[d][s] = 1;
  }
  else
    printf("wrong vertex");
}

// for deleting uni-directional edge
void dirdelete(int adj[max][max],int s,int d)
{
   if((s>=0 && s<max) && (d>=0 && d<max))
    adj[s][d] = 0;
  else
    printf("wrong vertex");
}

// for deleting bi-directional edge
void undirdelete(int adj[max][max],int s,int d)
{
  if((s>=0 && s<max) && (d>=0 && d<max))
  {
    adj[s][d] = 0;
    adj[d][s] = 0;
  }
  else
    printf("wrong vertex");
}

// for printing matrix
void matrix(int adj[max][max])
{
  for(int i=0;i<max;i++)
  {
    for(int j=0;j<max;j++)
    {
      printf("%d ",adj[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int choice,s,d;
  printf("enter number of vertex : ");
  scanf("%d",&max);
  int adj[max][max];

  for(int i=0;i<max;i++)
  {
    for(int j=0;j<max;j++)
    {
      adj[i][j] = 0;
    }
  }

  printf("1.for inserting a directed edge\n2.for inserting undirected edge\n3.for deleting a directed edge\n4.for deleting a undirected edge\n5.for printing matrix");
  do
  { 
    printf("\nenter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
             printf("enter source and destination vertex : ");
             scanf("%d %d",&s,&d);
             dirinsert(adj,s,d);
             break;
      case 2:
             printf("enter source and destination vertex : ");
             scanf("%d %d",&s,&d);
             undirinsert(adj,s,d);
             break;
      case 3:
             printf("enter source and destination vertex : ");
             scanf("%d %d",&s,&d);
             dirdelete(adj,s,d);
             break;
      case 4:
             printf("enter source and destination vertex : ");
             scanf("%d %d",&s,&d);
             undirdelete(adj,s,d);
             break;
      case 5:
             matrix(adj);
             break;
      default:
             printf("wrong choice");
             return 0;
    }
  }while(choice<=5);
  
}