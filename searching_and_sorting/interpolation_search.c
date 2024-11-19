#include<stdio.h>
int main()
{
    int a[]={11,22,33,44,55,66,77,88};
    int n = sizeof(a)/sizeof(int);
    int low=0,pos,high=n-1;
    int key;
    printf("enter element which you want to search : ");
    scanf("%d",&key);
    while(low<=high)
    {
        pos = low + (key - a[low]) / (a[high] - a[low]) * (high - low) ;
        if(key==a[pos])
        {
            printf("element found at position %d",pos+1);
            break;
        }
        else if(a[pos]>key)
            high = pos-1;
        else
            low=pos+1;
    } 
    if(low>high)
    {
        printf("not found");
    }

}