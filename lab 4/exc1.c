// write to generate fibonacci sequence using recursion
#include<stdio.h>
int fibb(int n);

int main()
{
    int num,a;
    printf("enter number how many sequence you want ?\n");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        a=fibb(i);
        printf("%d\t",a);
    }
}
int fibb(int n)
{
    int a,b;
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        a=fibb(n-1);
        b=fibb(n-2);
        return a+b;
    }
}