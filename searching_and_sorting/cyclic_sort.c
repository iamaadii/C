#include<stdio.h>
int main()
{
    int a[] = {3,1,2,5,4};
    int i=0;
    while(i<5)
    {
        int correct = a[i]-1;
        if(a[i]!=a[correct])
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

    printf("After sorting : ");
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
}