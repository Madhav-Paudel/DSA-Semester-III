// WAP to find gcd of two input number using recursion 
#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    int num1,num2,a;
    printf("enter first number to find the gcd of two number:\n");
    scanf("%d",&num1);
    printf("enter second number to find the gcd of two number\n");
    scanf("%d",&num2);
    a=gcd(num1,num2);
    printf(" The gcd of %d and %d is %d",num1,num2,a);

}