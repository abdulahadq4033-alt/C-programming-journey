#include <stdio.h>          		// Header file for input and output functions
#include <stdlib.h>         		// Header file for malloc() and free()

// Structure definition for doubly linked list node
struct node
{
    int data;               			// Stores data of the node
    struct node *prev;     		// Stores address of previous node
    struct node *next;     		// Stores address of next node
};

struct node *head = NULL;  		// Global pointer to first node

// Function to insert a node at the beginning
void insertBeginning(int value)
{
    struct node *newnode;                    				// Declare new node
    newnode = (struct node*)malloc(sizeof(struct node)); 		// Allocate memory

    newnode->data = value;                         				// Assign data
    newnode->prev = NULL;                          			// First node has no previous
    newnode->next = head;                          			// Point to old head

    if(head != NULL)                               			// If list is not empty
        head->prev = newnode;                      			// Update previous of old head

    head = newnode;                                			// Update head
}

// Function to insert a node at the end
void insertEnd(int value)
{
    struct node *newnode, *temp;                   			// Declare pointers
    newnode = (struct node*)malloc(sizeof(struct node)); 	// Allocate memory

    newnode->data = value;                         			// Assign data
    newnode->next = NULL;                          			// Last node next is NULL

    if(head == NULL)                               			// If list is empty
    {
        newnode->prev = NULL;                      			// No previous node
        head = newnode;                            			// New node becomes head
        return;
    }

    temp = head;                                  				// Start from head

    while(temp->next != NULL)                      		// Traverse to last node
        temp = temp->next;

    temp->next = newnode;                          			// Link last node to new node
    newnode->prev = temp;                          			// Link new node to last node
}

// Function to insert a node in between (after a given key)
void insertBetween(int key, int value)
{
    struct node *temp = head;                      			// Temporary pointer
    struct node *newnode;                          			// New node

    while(temp != NULL && temp->data != key)       	// Search for key
        temp = temp->next;

    if(temp == NULL)                               			// If key not found
    {
        printf("Key not found\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node)); 	// Allocate memory
    newnode->data = value;                         			// Assign data

    newnode->next = temp->next;                    		// Link new node to next
    newnode->prev = temp;                          			// Link new node to previous

    if(temp->next != NULL)                         			// If not inserting at end
        temp->next->prev = newnode;                		// Update previous link

    temp->next = newnode;                          			// Link temp to new node
}

// Function to delete node at beginning
void deleteBeginning()
{
    struct node *temp;                             			// Temporary pointer

    if(head == NULL)                               			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    temp = head;                                  				// Store head node
    head = head->next;                             			// Move head to next node

    if(head != NULL)                               			// If list not empty now
        head->prev = NULL;                         			// Set previous as NULL

    free(temp);                                   				// Free memory
}

// Function to delete node at end
void deleteEnd()
{
    struct node *temp = head;                      			// Temporary pointer

    if(head == NULL)                               			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)                         			// If only one node
    {
        free(head);                                				// Free node
        head = NULL;                               			// Set head NULL
        return;
    }

    while(temp->next != NULL)                      		// Traverse to last node
        temp = temp->next;

    temp->prev->next = NULL;                       		// Break link
    free(temp);                                   				// Free last node
}

// Function to delete an intermediate node (by value)
void deleteBetween(int key)
{
    struct node *temp = head;                      			// Temporary pointer

    if(head == NULL)                               			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL && temp->data != key)       	// Search key
        temp = temp->next;

    if(temp == NULL)                               			// If key not found
    {
        printf("Node not found\n");
        return;
    }

    if(temp == head)                               			// If deleting first node
    {
        deleteBeginning();
        return;
    }

    if(temp->next == NULL)                         			// If deleting last node
    {
        deleteEnd();
        return;
    }

    temp->prev->next = temp->next;                 		// Adjust previous link
    temp->next->prev = temp->prev;                 		// Adjust next link
    free(temp);                                   				// Free node
}

// Function to display doubly linked list
void display()
{
    struct node *temp = head;                      			// Temporary pointer

    if(head == NULL)                               			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List:\n");

    while(temp != NULL)                            			// Traverse list
    {
        printf("%d <-> ", temp->data);             			// Print data
        temp = temp->next;                         			// Move pointer
    }

    printf("NULL\n");                              			// End of list
}

// Main function
int main()
{
    int choice, value, key;                        			// Variable declaration

    do                                     				// Infinite loop
    {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Between\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete in Between\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertBetween(key, value);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteBetween(key);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);   
                break;                        					// Exit program

            default:
                printf("Invalid choice\n");
                break;
        }
    }while(choice!=8);

    return 0;                                      					// End program
}
