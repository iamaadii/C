//using recursion

#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else if(a==0)
        return b;
    else
        gcd(b,a%b);
}

void main()
{
    int a,b;
    printf("enter a and b: ");
    scanf("%d %d",&a,&b); 
    printf("gcd = %d",gcd(a,b));
}


// #include <stdio.h>
// int main() 
// {
// int a,b,gcd,i;
// printf("enter a and b: ");
// scanf("%d %d",&a,&b);
// for(i=1;i<=a&&i<=b;i++)
// {
//     if(a%i==0&&b%i==0)
//     {
//     gcd=i;
//     }
// }
// printf("gcd = %d",gcd);
//     return 0;
// }