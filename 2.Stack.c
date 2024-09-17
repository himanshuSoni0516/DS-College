//Write a menu based program that perform insert/push, display and delete/pop in stack.

#include<stdio.h>
#define MAX 5

int stack[MAX], top =-1;

void push(){
    if(top == MAX -1)
        printf("Stack Overflow\n");
    else{
        int val;
        printf("Enter value to push: \n");
        scanf("%d",&val);
        stack[++top] = val;
    }    
}

void pop(){
    if(top == -1)
        printf("Stack underflow\n");
    else{
        printf("Popped: %d\n", stack[top--]);
    }
}

void display(){
    if (top == -1)
        printf("Stack is Empty");
    else{
        printf("Stack: ");
        for( int i = top; i>=0; i--)
            printf("%d", stack[i]);
        printf("\n");
    }
}

int main(){
    int choice;
    while (1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoose: ");
        scanf("%d",&choice);
            switch (choice){
                case 1: push(); break;
                case 2: pop(); break;
                case 3: display(); break;
                case 4: return 0;
                default: printf("Invalid Choice\n");
            }
        }
}