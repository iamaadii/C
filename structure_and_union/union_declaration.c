// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
union student
{
    int rollno;
    char name[20];
    int cgpa;
}s;

int main() {
    s.rollno = 32;
    strcpy(s.name,"aditya");
    s.cgpa = 65;
    printf("%d\n",s.rollno);
    printf("%s\n",s.name);
    printf("%d\n",s.cgpa);
    
    return 0;
}