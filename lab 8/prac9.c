// write a program to implement the Binary search.
#include<stdio.h>
#define n 10
void insertionsort (int a[],int y);
void binary_search (int a[],int ch,int left,int mid,int right);
int main( )
{
int a[n],i,ch;
printf ("\n****Binary Searching****\n\n");
printf ("\nEnter the 10 numbers\n");
for(i=0;i<n;i++)
{
scanf ("%d",&a[i]);
}
insertionsort (a,n);
printf ("\nEnter the number to search\n");
scanf ("%d",&ch);
binary_search (a,ch,0,n/2,n);
printf ("\n%d was not found",ch);
}
// this function sort the data at the first  
void insertionsort (int a[],int y)
{
int j,i,hold;
for(i=0;i<y;i++)
{
hold=a[i];
for(j=i-1;j>=0&&a[j]>hold;j--)
{
a[j+1]=a[j];
a[j]=hold;
}
}
printf ("\nSorted data are\n");
for(i=0;i<n;i++)
printf ("\n%d",a[i]);
}
void binary_search (int a[],int ch,int left,int mid,int right)
{
int loc;
if ((mid-1)>=left&&((mid-1)<right))
{
if (ch==a[mid-1])
{
loc=mid;
printf ("\n%d was found in %d position",ch,loc);
exit(1);
}
if (ch<a[mid-1])
binary_search (a,ch,0,mid/2,mid);
if (ch>a[mid-1])
binary_search (a,ch,mid,(n+mid+1)/2,n);
}
}