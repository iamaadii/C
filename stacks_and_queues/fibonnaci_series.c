// C Program to print the Fibonacci series using recursion

#include <stdio.h>
int fib(int n)
{
    if (n == 1) 
      return 0;
    
    else if (n == 2) 
      return 1;
  
    else 
      return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    printf("enter number of terms : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      printf("%d ",fib(i));
}




// #include <stdio.h>
// int main() 
// {
//   int i, n;
//   int t1 = 0, t2 = 1;
//   int nextTerm = t1 + t2;

//   printf("Enter the number of terms: ");
//   scanf("%d", &n);

//   printf("Fibonacci Series: %d, %d, ", t1, t2);

//   for (i = 3; i <= n; ++i) 
//   {
//     printf("%d, ", nextTerm);
//     t1 = t2;
//     t2 = nextTerm;
//     nextTerm = t1 + t2;
//   }
//   return 0;
// }



