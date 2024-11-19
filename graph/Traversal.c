#include<stdio.h>
#include<string.h>

#define max 7

int a[max][max] = {0};

void insert(int s,int d)
{
    if((s<max && s>=0) && (d>=0 && d<max))
    {
      a[s][d] = 1;
      a[d][s] = 1;
    }
    else
      printf("wrong vertices");
}

void matrix()
{
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void bfs(int current)
{
    int queue[max];
    int rear=0,front = 0;
    int visited[max] = {0};
    visited[current] = 1;
    queue[rear++] = current;
    while(front<rear)
    {
        int result = queue[front++];
        printf("%d ",result);
        for(int i = 0; i<max; i++)
        {
            if(a[i][result] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// void dfs(int current, int visited[max])
// {
//     visited[current] = 1;
//     printf("%d ",current);
//     for(int i = 0; i<max; i++)
//     {
//         if(a[current][i] == 1 && visited[i] == 0)
//             dfs(i,visited);
//     }
// }

void dfs(int startvertex, int visited[max])
{
    int stack[100];
    int top=-1;
    visited[startvertex]=1;
    stack[++top]=startvertex;
    while(top!=-1)
    {
        int currentvertex=stack[top--];
        printf("%d ",currentvertex);
        for(int i=0;i<7;i++)
        {
            if(a[currentvertex][i]==1 && visited[i] == 0)
            {
                visited[i]=1;
                stack[++top]=i;
            }
        }
    }
}

int main() 
{
    int visited[max] = {0};
    insert(0, 1);
    insert(0, 3);
    insert(3, 1);
    insert(3, 2);
    insert(3, 4);
    insert(2, 4);
    insert(4, 6);
    insert(1, 6);
    insert(2, 5);
    insert(1, 5);
    
    matrix(); // Print adjacency matrix
    
    printf("\nBFS Traversal: ");
    bfs(0); // Perform BFS
    printf("\n");
    printf("\nDFS Traversal: ");
    dfs(0,visited); // Perform DFS
    printf("\n");
    
    return 0; 
}