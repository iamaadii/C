#include<stdio.h>
int main()
{
    int a[]={12,29,25,8,32,17,40};
    int n=sizeof(a)/sizeof(int);
    int i,j,min;

    printf("before sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    for(i=0;i<n-1;i++)  //two parts sorted part and unsorted part initially sorted part will be empty
    {
        min = i; //assuming element of index i is smaller  
        for(j=i+1;j<n;j++) // comparing each element with min element if any element is smaller than min elemnt then assign min = index of new min element
        {
            if(a[j]<a[min])
                min=j;
        }
        int temp=a[i]; //swapping new minimum element with the last element in sorted list
        a[i]=a[min];
        a[min]=temp;
    }

    printf("\nafter sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}