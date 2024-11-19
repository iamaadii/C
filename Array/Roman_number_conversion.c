#include <stdio.h>
#include<string.h>

int roman(char c)
{
    switch(c)
    {
        case 'I' : 
                return 1;
        case 'V' :
                return 5;
        case 'X' :
                return 10;
        case 'L' :
                return 50;
        case 'C' :
                return 100;
        case 'D' :
                return 500;
        case 'M' :
                return 1000;
        default :
                return 0;
    }
}

int main() 
{
int i;
char a[20];
printf("enter roman number : ");
scanf("%s",a);
int n = strlen(a);
int sum=0;
for(i=0;i<n;i++)
{
    if(i<n-1 && roman(a[i])<roman(a[i+1]))
    {
        sum=sum-roman(a[i]);
    }
    else
    {
        sum=sum+roman(a[i]);
    }
}
printf("result : %d",sum); 
}