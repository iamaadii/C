//using recurison
#include <stdio.h>
int fact(int n)
{
  if(n==0 || n==1)
    return 1;
  else
  return n*fact(n-1);
}

int main()
{
   int n=-1;
   printf("\nfactorial : %d",fact(n));
}

// #include<stdio.h>
// int main()
// {
//     int fact = 1;
//     int n=5;
//     for(int i=1;i<=n;i++)
//     { 
//       fact = fact * i;
        
//     }
//     printf("factorial : %d",fact);
// }