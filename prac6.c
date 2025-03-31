// write the menu driven program to implement doubly linked list operations.
//a)Inserting the node at the beginning.
//b)inserting the node the specific position.
//c)Deleting the node from the specific operation.
//d)traverse and display.
//e)exit.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void insertfirst( );
void insertspecificposition( );
void deletenodefromspecificposition( );
void traverse( );
struct list
{
    int info;
    struct list *next;
    struct list *prev;
};
typedef struct list node;
node *start = '\0';
int main ( )
{
    int choice;
    while(1)
    {
        printf("\n1.Insert at the beginning:");
        printf("\n2.Insert at the specific position:");
        printf("\n3.Delete a node from the specific position:");
        printf("\n4.Traverse and display:");
        printf("\n5.Exit:");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertfirst( );
            break;

            case 2:
            insertspecificposition( );
            break;
            case 3:
            deletenodefromspecificposition( );
            break;
            case 4:
            traverse( );
            break;
            case 5:
            exit(0);
            default:
            printf("The choice you entered is not valid");
        }
    }
    return 0;
}
void insertfirst ( )
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    printf("\nEnter the data to insert");
    scanf("%d", &ptr->info);
    if(start=='\0')
    {
        start=ptr;
        ptr->next='\0';
        ptr->prev='\0';
    }
    else
    {
        ptr->prev='\0';
        ptr->next=start;
        start->prev=ptr;
        start=ptr;
    }
    printf("\nData has been inserted at first position in the list");
}


void insertspecificposition( )
{
    int count=1;
    int n;
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    printf("\nEnter the data to insert");
    scanf("%d",&ptr->info);
    printf("\nEnter the node after which you want to insert a new node:");
    scanf("%d",&n);
    temp=start;
    while(count<n)
    {
        count ++;
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    temp->next->prev=ptr; 
    ptr->prev=temp;
    printf("\nData has been inserted at the specific position in the list");
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
        while(temp!='\0')
        {
            printf("\n%d", temp->info);
            temp=temp->next;
        }
    }
}

void deletenodefromspecificposition( )
{
    node *temp,*ptr;
    int n;
    int count=1;
    printf("\nEnter the node number that you want to delete:");
    scanf("%d",&n);
    ptr=start;
    while(count<n)
    {
        count ++;
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    ptr->next->prev=ptr; 
    printf("The deleted item is %d",ptr->info); 
    free(ptr); 
}



// algorithm 
/*
*Algorithm for inserting the node at the beginning
{

1.ptr=(node*)malloc(sizeof(node))
2.set ptr-> info=item
3.if start==NULL
 -ptr->next=NULL
 -ptr->prev=NULL
 -start=ptr
4. else
-ptr->next=start
-start->prev=ptr
-ptr->ptr=NULL
-start=ptr

}



*Algorithm for inserting the new node at the specific position 
{
1.ptr=(node*)malloc(sizeof(node))
2.set ptr->info=item
3.Declare and initialize necessary variables such as n,counter=1
4.Ask the user after which node he/she want to insert a new node say 'n'
5.set temp=start
6.while(count<n)
  {
   count++;
   temp=temp->next
  }

7.set ptr->next=temp->next
8.set temp->next->prev=ptr
9.set temp->next=ptr
10.set ptr->prec=temp
}
*Algorithm for deleting the node form specific position 
{
1.if start==NULL
-print "list is empty "
2.else
-declare and initialize necessary variables such as count=1, n
-Ask the user which node he/she want to delete say 'n'
-set ptr = start
3.while(count<n)
{
 count++
 set temp=ptr 
 ptr=ptr->next 
}
4.set temp-> next
 =ptr->next 
5.set ptr->next->prev=temp
6.print"the deleted item is" ptr->info
7.free(ptr) 


} 


*/