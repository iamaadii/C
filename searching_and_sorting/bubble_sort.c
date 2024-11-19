#include<stdio.h>
int main()
{
    int a[]={9,5,12,56,78,56,90,24,225,46,24};
    int n=sizeof(a)/sizeof(int);
    int i,j;

    printf("before sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    for(i=0;i<n-1;i++)
    {
        //int flag =0;  
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                //flag=1;
            }
        }
        // if(flag==0)
        //     break;
    }

    printf("\nafter sorting : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}