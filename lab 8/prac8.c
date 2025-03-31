// write a program to implement the linear search (sequential search) algorithm.
# include<stdio.h>
#define n 10
void linear(int a[]);

int main()
{
    int a[n],i;
    printf("\nLinear Searching\n");
    printf("\nEnter the 10 numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    linear(a); 
    return 0;


}
void linear(int a[])
{
    int i,loc=-1,ch;
    printf("\nEnter the number to search\n");
    scanf("%d",&ch);
    for(i=0;i<n;i++)
    {
        if(a[i]==ch)
        {
            loc=i+1;
            break;
        }
    }
    if(loc>=0)
    {
        printf("\n%d was found in %d position",ch,loc);

    }
    else{
        printf("\n%d was not found",ch);
    }

}