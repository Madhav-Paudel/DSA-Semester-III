// write a menu driven program to implement linear queue operations:
// enqueue
// dequeue
// display_all_elements(traverse)
// display front element
// exit
#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display_all_elements();
void display_front_element();
int queue[5],max_size=5;
int front=0,rear=-1;
void enqueue()
{
    if(rear>=max_size-1)
    {
        printf("queue is full\n");
    }
    else
    {
        printf("enter element you want to enqueue\n");
        int val;
        scanf("%d",&val);
        rear=rear+1;
        queue[rear]=val;

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
        front=front+1;
        printf("%d is remove from queue\n",item);
    }
}

void display_front_element()
{
    if (rear < front)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

void display_all_elements()
{
    if (rear < front)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
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
        printf("5: To display the front element\n");
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
            case 5:
            display_front_element();
            break;
            default:
            printf("invalid 101 error!");
            break;
        }
    }

}
