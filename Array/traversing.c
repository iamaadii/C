#include<stdio.h>
int main()
{
    int a[] = {23,34,56};
    int n = sizeof(a)/sizeof(a[0]);
    int i;
    int *p = a;
    for(i=0;i<n;i++)
    printf("%d ",*(p+i));
}
