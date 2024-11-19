#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int b[low+high];
    int i=low;
    int j=mid+1;
    int k=low;

    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++; k++;
        }
        else
        {
            b[k]=a[j];
            j++;k++;
        }
    }
    if(i>mid) 
    {
        while(j<=high)
        {
            b[k] = a[j];
            j++;k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];
            i++;k++;
        }
    }
    for(int k=low;k<=high;k++)
        a[k]=b[k];
}

void partition(int a[],int low,int high)
{
    if(high>low)
    {
        int mid = low+(high-low)/2;
        partition(a,low,mid);
        partition(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    int a[]={10,5,28,7,39,310,55,15,1};
    int n=sizeof(a)/sizeof(int);
    int low=0,high=n-1;

    printf("before sorting : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    partition(a,low,high);

    printf("\nafter sorting : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
