//Write a menu base program that insert, delete, show values in circular queue

#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue() {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue Overflow!\n");
    } else {
        int val;
        printf("Enter value to insert: ");
        scanf("%d", &val);
        if (front == -1)  // First element
            front = rear = 0;
        else if (rear == MAX - 1 && front != 0)
            rear = 0;
        else
            rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear)  // Only one element
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}

void display() {
    if (front == -1)
        printf("Queue is empty!\n");
    else {
        printf("Queue: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}


