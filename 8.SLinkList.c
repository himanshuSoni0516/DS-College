//Write a menu base program using simple linklist and perform taske-
//1.insert, 2.delete from first, 3.delete from last, 4.delete from between, 5.display, exit.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end
void insert(struct Node** head) {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // First node in the list
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the first
void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
    }
}

// Function to delete a node from the last
void deleteFromLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
    } else if ((*head)->next == NULL) {  // Only one element in the list
        printf("Deleted node with value: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Deleted node with value: %d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to delete a node from between (specific position)
void deleteFromBetween(struct Node** head) {
    int pos, i = 1;
    printf("Enter the position to delete from: ");
    scanf("%d", &pos);

    if (*head == NULL) {
        printf("List is empty!\n");
    } else if (pos == 1) {
        deleteFromFirst(head);  // If position is 1, delete the first node
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;

        for (i = 1; temp != NULL && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of range.\n");
        } else {
            prev->next = temp->next;
            printf("Deleted node with value: %d\n", temp->data);
            free(temp);
        }
    }
}

// Function to display the list
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

// Main function
int main() {
    struct Node* head = NULL;  // Initialize empty linked list
    int choice;
    
    while (1) {
        printf("\n1. Insert\n2. Delete from First\n3. Delete from Last\n4. Delete from Between\n5. Display\n6. Exit\nChoose: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insert(&head); break;
            case 2: deleteFromFirst(&head); break;
            case 3: deleteFromLast(&head); break;
            case 4: deleteFromBetween(&head); break;
            case 5: display(head); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
