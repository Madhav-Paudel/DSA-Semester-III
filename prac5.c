// Write a menu driven program to implement single linear linked list operation 
// 1. Insert node at the beginning 
// 2. Delete the last node 
// 3. Traverse and display 
// 4. Searching 


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void insertfirst( );
void deletelast( );
void traverse( );
void search( );
struct list
{
    int info;
    struct list *next;
};
typedef struct list node;
node *start;
int main( )
{
    int choice;
    while(1)
    {
        printf("\n1.Insert at the beginning:");
        printf("\n2.Delete last node:");
        printf("\n3.Traverse and display:");
        printf("\n4.Searching:");
        printf("\n5.Exit:");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertfirst( );
            break;
            case 2:
            deletelast( );
            break;
            case 3:
            traverse( );
            break;
            case 4:
            search( );
            break;
            case 5:
            exit(0);
            default:
            printf("The choice you entered is not valid");
        }
    }
    return 0;
}
void insertfirst( )
{
    node *item;
    item=(node*)malloc(sizeof(node));
    printf("\nEnter the data to insert");
    scanf("%d",&item->info);
    if(start=='\0')
    {
        start=item;
        item->next='\0';
    }
    else
    {
        item->next=start;
        start=item;
    }
    printf("\nData has been inserted at first position in the list");
}
void deletelast( )
{
    node *ptr,*loc;
    if(start=='\0')
    {
        printf("\n list is empty");
    }
    else if(start->next=='\0')
    {
        printf("\nThe deleted number is %d",start->info);
        free(start);
        start='\0';
    }
    else
    {
        ptr=start;
        while(ptr->next!='\0')
        {
            loc=ptr;
            ptr=ptr->next;
        }
        loc->next='\0';
        printf("\nThe deleted number is %d",ptr->info);
        free(ptr);
    }
}
void traverse( )
{
    node *temp;
    if(start=='\0')
    {
        printf("\nThere are no data present in the list");
    }
    else
    {
        printf("\nThe Data are");
        temp=start;
        while(temp->next!='\0')
        {
            printf("\n%d",temp->info);
            temp=temp->next;
        }
        printf("\n%d",temp->info);
    }
}
void search( )
{
    int n,i=1;
    node *temp;
    start:
    printf("\nEnter the data to search");
    scanf("%d",&n);
    if(start=='\0')
    {
        printf("\nThe list is empty");
    }
    else
    {
        temp=start;
        while(temp->info!=n)
        {
            if(temp->next=='\0')
            {
                printf("\nThe value doesnot exists");
                goto start;
            }
            temp=temp->next;
            i++;
        }
        printf("\nThe value %d is located at %d position",n,i);
    }
}