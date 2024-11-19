//print elements which is repeating more than half of the size of array
#include<stdio.h>
int main()
{
    int a[]={1,3,2,3,3};
    int n=sizeof(a)/sizeof(a[0]);
    int i,j,b;
    for(i=0;i<n;i++)
    {
        int temp=a[i];
        int count=1;
        for(j=0;j<n;j++)
        {
            if(a[j]==temp)
            {
                count++;
            }
        }
        if(count>n/2)
        {
            b=a[i];
        }
    }
    printf("%d ",b);
}