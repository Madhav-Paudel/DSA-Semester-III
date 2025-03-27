// WAP to implement TOH problem using recursion 
#include<stdio.h>
void transfer (int n, char from, char to, char temp);
int main()
{
    int n;
    printf("\nEnter the number of disks\n");
    scanf("%d",&n);
    transfer(n,'L','R','C');
}
void transfer (int n, char from, char to, char temp)
{
    if(n==0)
    {
        return;
    }
    else
    {
        transfer(n-1,from,temp,to);
        printf("\nMove disk %d from %c to %c",n,from,to);
        transfer(n-1,temp,to,from);
    }
}