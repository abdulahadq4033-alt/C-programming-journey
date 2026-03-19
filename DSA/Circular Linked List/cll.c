#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;

    // Go to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete a node by value
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    // If head node is to be deleted
    if (head->data == key) {
        // Only one node
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        // Find last node
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = head->next;
        struct Node* del = head;
        head = head->next;
        free(del);
        return;
    }

    // Search for node
    prev = head;
    temp = head->next;

    while (temp != head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == head) {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Traverse the circular linked list
void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Delete\n4.Traverse\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 4:
                traverse();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}