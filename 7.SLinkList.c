//Write a menu base program using simple linklist and perform taske-
//1.insert at first, 2.insert at last, 3.insert node between, 4.search node, 5.display, exit.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the beginning
void insertAtFirst(struct Node** head) {
    int val;
    printf("Enter value to insert at first: ");
    scanf("%d", &val);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at the end
void insertAtLast(struct Node** head) {
    int val;
    printf("Enter value to insert at last: ");
    scanf("%d", &val);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node between two nodes
void insertBetween(struct Node** head) {
    int val, pos;
    printf("Enter position to insert node after: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position not found.\n");
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to search for a node
void searchNode(struct Node* head) {
    int key, found = 0, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &key);
    
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        pos++;
        temp = temp->next;
    }
    if (!found) {
        printf("Value %d not found.\n", key);
    }
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Linked List: ");
        while (head != NULL) {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice;
    
    while (1) {
        printf("\n1. Insert at First\n2. Insert at Last\n3. Insert Between\n4. Search Node\n5. Display\n6. Exit\nChoose: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insertAtFirst(&head); break;
            case 2: insertAtLast(&head); break;
            case 3: insertBetween(&head); break;
            case 4: searchNode(head); break;
            case 5: display(head); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
