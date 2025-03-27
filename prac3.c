// write a menu driven program to implement the circular queue operations
// 1.enqueue
// 2.dequeue
// 3.traverse(display all elements )
// 5. exit
#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display_all_elements();
int queue[5],max_size=5;
int front=0,rear=0;
void enqueue()
{
    if(front==(rear+1)%max_size)
    {
        printf("queue is full\n");
    }
    else
    {
        printf("enter element you want to enqueue\n");
        int val;
        scanf("%d",&val);
        queue[rear]=val;
        rear=(rear+1)%max_size;

    }
}     
void dequeue()
{
    if (rear<front)
    {
        printf("queue is empty\n");
    }
    else
    {
        int item;
        item=queue[front];
        front=(front+1)%max_size;
        printf("%d is remove from queue\n",item);
    }
}

void display_all_elements()
{
    int i;
    if (front==rear)
    {
        printf("circular queue is empty\n");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%max_size){
                    printf(" %d\t", queue[i]);
        }
    }
}



int main()
{
    int choose;
    while(1)
    {
        printf("\nEnter choice:\n");
        printf("1: enqueue\n");
        printf("2: dequeue\n");
        printf("3: Display all element\n");
        printf("4: Exit\n");
    
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display_all_elements();
            break;
            case 4:
            return 0;
            break;
            default:
            printf("invalid 101 error!");
            break;
        }
    }

}
