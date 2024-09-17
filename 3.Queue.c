//Write a menu base program that insert, display, delete values  in queue.

#include<stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enQueue(){
    if(rear == MAX -1)
        printf("Queue is overflow\n");
    else{
       int val;
       printf("Enter value to enQueue: \n");
       scanf("%d",&val);
       if(front == -1) front = 0;
       queue[++rear] = val; 
    }
}

void deQueue(){
    if(front == -1 || front > rear)
        printf("Queue underflow\n");
    else
        printf("Dequeued: %d\n", queue[front++]);
}

void display(){
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else{
        printf("Queue : ");
        for(int i = front; i <= rear; i++)
        printf("%d", queue[i]);
    printf("\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3.Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: enQueue(); break;
            case 2: deQueue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}