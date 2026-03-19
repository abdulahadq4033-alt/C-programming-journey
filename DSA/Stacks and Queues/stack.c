// Stack using arrays program

#include <stdio.h>
#include <stdlib.h>
#define size 10
int x, s[10], top = -1;
void push(){
    if(top == size - 1){
        printf("Stack overflow\n");
    }
    else{
        printf("Enter the element to be pushed: ");
        scanf("%d", &x);
        top++;
        s[top] = x;
    }
}
void pop(){
    if(top == -1){
        printf("Stack underflow\n");
    }
    else{
        printf("Popped element: %d\n", s[top]);
        top--;
    }
}
void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements: ");
        for(int i = top; i >= 0; i--){
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}
void main(){
    int choice;
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}