#include<stdio.h>
#include<stdlib.h>

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

void merge_sort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = low+(high-low)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void s_sort(int arr[],int n){
    for(int i=0;i<n-1;i++)
    {
        int min = i;  
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
void b_sort(int a[],int n){
    for(int i=0;i<n-1;i++)
    {
        int flag =0;  
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

void i_sort(int a[],int n){
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int partition(int a[],int low,int high)
{
    int pivot=a[low]; //pivot = first element of array
    int start = low;
    int end = high;

    while(end>start) 
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

void display(int a[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main()
{
    int a[]={25,3,78,1,0,10};
    int n=sizeof(a)/sizeof(int);
    int a1[n],a2[n],a3[n],a4[n];
    for(int i = 0; i<n;i++){
        a1[i]=a[i];
        a2[i]=a[i];
        a3[i]=a[i];
        a4[i]=a[i];
    }
    int low=0,high=n-1;
    printf("before sorting : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    quicksort(a,low,high);
    s_sort(a1,n); 
    b_sort(a2,n); 
    i_sort(a3,n); 
    merge_sort(a4,low,high); 
    printf("\nafter sorting : \n");
    printf("Quick Sort: ");
    display(a,n);
    printf("\nSelection Sort: ");
    display(a1,n);
    printf("\nBubble Sort: ");
    display(a2,n);
    printf("\nInsertion Sort: ");
    display(a3,n);
    printf("\nMerge Sort: ");
    display(a4,n);
    return 0;
}