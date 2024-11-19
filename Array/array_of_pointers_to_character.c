#include<stdio.h>
int main()
{
    char *a[]={"aditya","sandeep","rohit"};
    int i;
    int n = sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++)
    printf("%s ",a[i]);
    printf("%d",a[2]);
}