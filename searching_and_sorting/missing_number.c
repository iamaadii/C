//Find the missing number from an array contains n distinct number in the range of [0,n] --problem 268 leetcode

#include<stdio.h>
int main()
{
    int a[] = {9,6,4,2,3,5,7,0,1};
    int n = sizeof(a)/sizeof(int);
    int i=0;
    while(i<n)
    {
        int correct = a[i];
        if((a[i]<n) && (a[i]!=a[correct]))
        {
            int temp = a[i];
            a[i] = a[correct];
            a[correct] = temp;
            i = 0;         
        }
        else
        {
            i++;
        }
    }

    printf("missing number : ");
    
    for(i=0;i<n;i++)
    {
        if(a[i]!=i)
        {
            printf("%d ",i);
            return 0;
        }
        
    }
    printf("%d",n);
}