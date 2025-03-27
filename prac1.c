// write a menu driven program to implement stack operations
// push
// pop
// display all the elements (traverse)
// display top
// exit
#include <stdio.h>
#include <stdlib.h>

int stack[5], Maxsize = 5, top = -1;

void Push();
void Pop();
void display(); 

void Push() {
    if (top >= Maxsize - 1) {
        printf("stack is full\n");
    } else {
        printf("Enter number you want to push: ");
        int num;
        scanf("%d", &num);
        top++;
        stack[top] = num;
         printf("Element pushed on top!\n");
    }
}

void Pop() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        int num = stack[top];
        top--;
        printf("The number %d at the top of the stack was popped.\n", num);
    }
}
void display(){
  if (top == -1)
     {
       printf("Stack is empty.\n");
        }
      else {
         printf("Current Stack: \n");
         for (int i= top; i>=0; i--){
                printf("%d ", stack[i]);
              }
        printf("\n");
       }
}
void display_top()
{
     if (top == -1)
     {
       printf("Stack is empty.\n");
        }
        else
        {
    printf("The current value of Top in the stack  is: %d ",top);
        }
}
int main() {
    int choose;
    
    while (1) {
        printf("\nEnter choice:\n");
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Display stack\n");
        printf("4: Exit\n");
        printf("5: To display the top\n");
         scanf("%d", &choose); 

        switch (choose) {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
           case 3:
                 display();
               break;
             case 4:
                 printf("Exiting Program\n");
                 return 0; 
                 break;
                  case 5:
                 display_top();
               break;

            default:
                printf("Invalid Input 404 Error\n");
                break;
        }
    }
    
    return 0;
}