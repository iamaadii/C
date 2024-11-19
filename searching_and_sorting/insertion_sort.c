/*two part is present sorted and unsorted initially one element will be present in sorted element 
and rest of the elements will be present in unsorted ... Initially we will store a[i] element in a temp var
and then we will compare it with a[i-1] element till 'i' becomes zero if a[i-1] element is greater than a[i] 
then we wil simply assign a[i] = a[i-1] this process will continue till i<n...
*/ 

#include<stdio.h>
int main()
{
    int a[]={25,3,78,1,0,10};
    int n=sizeof(a)/sizeof(int);
    int i,j,temp;

    printf("before sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    printf("\nafter sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        
}
