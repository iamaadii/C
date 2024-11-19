#include<stdio.h>
void quicksort(int [],int,int);  //function declartion
int partition(int [],int,int);
int main()
{
    int a[]={7,6,10,5,9,2,1,15,7};
    int n=sizeof(a)/sizeof(int);
    int low=0,high=n-1;

    printf("before sorting : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    quicksort(a,low,high); 

    printf("\nafter sorting : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

int partition(int a[],int low,int high)
{
    int pivot=a[low]; //pivot = first element of array
    int start = low;
    int end = high;

    while(end>=start) 
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(end>start)
        {
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    int temp = a[end]; //if start > end then it will simply swap element of end position with pivot element
    a[end] = a[low];
    a[low] = temp;
    return end; // returning index of pivot element in sorted order
}

void quicksort(int a[],int low,int high)
{
    if(high>low)
    {
        int mid=partition(a,low,high); 
        quicksort(a,low,mid-1); //process will be repeated from index 0 to mid-1 
        quicksort(a,mid+1,high); //process will be repeated from index mid+1 to n-1
    }
}