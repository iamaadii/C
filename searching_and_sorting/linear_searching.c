#include<stdio.h>
int main()
{
    int a[]={24,25,3,85};
    int n=sizeof(a)/sizeof(int);
    int key,i;
    printf("enter element which you want to search : ");
    scanf("%d",&key);
    int found = 0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("found at %d position",i+1); //if key = a[i] then it will simply prints its postion and break the loop
            found=1;
            break;
        }
    }
    if(found==0)
        printf("not found");
}