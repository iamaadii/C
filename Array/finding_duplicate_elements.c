#include<stdio.h>
int main()
{
    int a[]={1,2,3,4,5,9,5,12,56,78,56,90,24,225,46,24};
    int n=sizeof(a)/sizeof(int);
    int i,j,count=0;
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                printf("%d ",a[i]);
                count++;
            }
        }
    }
    if(count==0)
    printf("no repeated element");
}