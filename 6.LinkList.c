//Write a menu base program to add node at start of linklist also write a function to display values of all nodes

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the start
void addAtStart(struct Node** head) {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value to insert: ");
    scanf("%d", &val);
    
    newNode->data = val;
    newNode->next = *head; // Link new node with the current head
    *head = newNode;       // Move head to point to the new node
}

// Function to display all nodes
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        printf("Linked List: ");
        while (head != NULL) {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* head = NULL; // Initialize empty linked list
    int choice;
    
    while (1) {
        printf("\n1. Add node at start\n2. Display all nodes\n3. Exit\nChoose: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addAtStart(&head); break;
            case 2: display(head); break;
            case 3: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
