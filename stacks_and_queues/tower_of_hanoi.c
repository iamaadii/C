#include<stdio.h>
void toh(int,char,char,char);
int main()
{
    int n;  
    printf("enter number of disks : ");
    scanf("%d",&n);
    printf("tower of hanoi of %d disc\n",n);
    toh(n,'a','b','c');
    return 0;
}
void toh(int n,char source,char auxillary,char destination)
{
    if(n<=0)   
      printf("wrong input\n");
    else if(n==1)
      printf("move disc from %c to %c\n",source,destination);
    else
    {
      toh(n-1,source,destination,auxillary); 
      toh(1,source,auxillary,destination);
      toh(n-1,auxillary,source,destination);
    }    
}