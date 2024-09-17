#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert at the beginning
void insertAtFirst(struct Node** head) {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert at first: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert at the end
void insertAtLast(struct Node** head) {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert at last: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert at a specific position
void insertAtPosition(struct Node** head) {
    int pos, val, i = 1;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    newNode->data = val;
    if (pos == 1) {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete from the beginning
void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
}

// Function to delete from the end
void deleteFromLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == NULL) {  // Only one element
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted node with value: %d\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete from a specific position
void deleteFromPosition(struct Node** head) {
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    if (pos == 1) {
        deleteFromFirst(head);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
}

// Function to display the list forward
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List (Forward): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to display the list backward
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Linked List (Backward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to search for an element
void searchNode(struct Node* head) {
    int key, pos = 1, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);

    while (head != NULL) {
        if (head->data == key) {
            printf("Value %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        pos++;
        head = head->next;
    }

    if (!found) {
        printf("Value %d not found in the list.\n", key);
    }
}

// Main function to perform operations
int main() {
    struct Node* head = NULL;  // Initialize the list
    int choice;

    while (1) {
        printf("\n1. Insert at First\n2. Insert at Last\n3. Insert at Position\n4. Delete from First\n5. Delete from Last\n6. Delete from Position\n7. Display Forward\n8. Display Backward\n9. Search Node\n10. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtFirst(&head); break;
            case 2: insertAtLast(&head); break;
            case 3: insertAtPosition(&head); break;
            case 4: deleteFromFirst(&head); break;
            case 5: deleteFromLast(&head); break;
            case 6: deleteFromPosition(&head); break;
            case 7: displayForward(head); break;
            case 8: displayBackward(head); break;
            case 9: searchNode(head); break;
            case 10: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}