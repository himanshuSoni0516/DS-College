//Write a menu base program using double ended queue to perform tasks - 
//1. Insert, 2. Delete, 3. Display, 4. Insert at first, 5. Delete from last, 6. Display reverse 

#include <stdio.h>
#define MAX 5

int deque[MAX], front = -1, rear = -1;

void insertRear() {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1)))
        printf("Deque Overflow!\n");
    else {
        int val;
        printf("Enter value to insert: ");
        scanf("%d", &val);
        if (front == -1)  // First element
            front = rear = 0;
        else if (rear == MAX - 1 && front != 0)
            rear = 0;
        else
            rear++;
        deque[rear] = val;
    }
}

void insertFront() {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1)))
        printf("Deque Overflow!\n");
    else {
        int val;
        printf("Enter value to insert at front: ");
        scanf("%d", &val);
        if (front == -1)  // First element
            front = rear = 0;
        else if (front == 0)
            front = MAX - 1;
        else
            front--;
        deque[front] = val;
    }
}

void deleteFront() {
    if (front == -1)
        printf("Deque Underflow!\n");
    else {
        printf("Deleted: %d\n", deque[front]);
        if (front == rear)  // Only one element
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}

void deleteRear() {
    if (front == -1)
        printf("Deque Underflow!\n");
    else {
        printf("Deleted from rear: %d\n", deque[rear]);
        if (front == rear)  // Only one element
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
}

void display() {
    if (front == -1)
        printf("Deque is empty!\n");
    else {
        printf("Deque: ");
        int i = front;
        while (i != rear) {
            printf("%d ", deque[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", deque[rear]);
    }
}

void displayReverse() {
    if (front == -1)
        printf("Deque is empty!\n");
    else {
        printf("Deque in reverse: ");
        int i = rear;
        while (i != front) {
            printf("%d ", deque[i]);
            i = (i - 1 + MAX) % MAX;
        }
        printf("%d\n", deque[front]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at rear\n2. Delete from front\n3. Display\n4. Insert at front\n5. Delete from rear\n6. Display reverse\n7. Exit\nChoose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertRear(); break;
            case 2: deleteFront(); break;
            case 3: display(); break;
            case 4: insertFront(); break;
            case 5: deleteRear(); break;
            case 6: displayReverse(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
