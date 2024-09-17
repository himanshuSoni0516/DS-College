#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertAtFirst(struct Node** head) {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert at first: ");
    scanf("%d", &val);
    
    newNode->data = val;
    if (*head == NULL) {
        newNode->next = newNode; // For the first node, it points to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;  // Update head to the new node
    }
}

// Function to insert a node at the end
void insertAtLast(struct Node** head) {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert at last: ");
    scanf("%d", &val);

    newNode->data = val;
    if (*head == NULL) {
        newNode->next = newNode;  // First node points to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head) {
    int pos, val, i = 1;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    newNode->data = val;
    if (pos == 1) {
        insertAtFirst(head);
    } else {
        struct Node* temp = *head;
        for (i = 1; i < pos - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        if (temp->next == *head && i != pos - 1) {
            printf("Position out of range.\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to delete a node from the beginning
void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
    } else if ((*head)->next == *head) {
        printf("Deleted node with value: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        printf("Deleted node with value: %d\n", temp->data);
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

// Function to delete a node from the end
void deleteFromLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
    } else if ((*head)->next == *head) {
        printf("Deleted node with value: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        printf("Deleted node with value: %d\n", temp->data);
        prev->next = *head;
        free(temp);
    }
}

// Function to delete a node from a specific position
void deleteFromPosition(struct Node** head) {
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (*head == NULL) {
        printf("List is empty!\n");
    } else if (pos == 1) {
        deleteFromFirst(head);
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;

        for (i = 1; i < pos && temp->next != *head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == *head && i != pos) {
            printf("Position out of range.\n");
        } else {
            prev->next = temp->next;
            printf("Deleted node with value: %d\n", temp->data);
            free(temp);
        }
    }
}

// Function to search for an element in the circular linked list
void searchNode(struct Node* head) {
    int key, pos = 1, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);
    
    struct Node* temp = head;
    if (head != NULL) {
        do {
            if (temp->data == key) {
                printf("Value %d found at position %d.\n", key, pos);
                found = 1;
                break;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
    }
    if (!found) {
        printf("Value %d not found in the list.\n", key);
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct Node* temp = head;
        printf("Circular Linked List: ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("HEAD\n");
    }
}

// Main function to perform operations
int main() {
    struct Node* head = NULL;  // Initialize the list
    int choice;

    while (1) {
        printf("\n1. Insert at First\n2. Insert at Last\n3. Insert at Position\n4. Delete from First\n5. Delete from Last\n6. Delete from Position\n7. Search Node\n8. Display List\n9. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtFirst(&head); break;
            case 2: insertAtLast(&head); break;
            case 3: insertAtPosition(&head); break;
            case 4: deleteFromFirst(&head); break;
            case 5: deleteFromLast(&head); break;
            case 6: deleteFromPosition(&head); break;
            case 7: searchNode(head); break;
            case 8: display(head); break;
            case 9: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}