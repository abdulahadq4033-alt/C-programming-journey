#include <stdio.h>          				// Includes standard input-output functions
#include <stdlib.h>         				// Includes memory allocation functions

// Structure definition of a node
struct node
{
    int data;               					// Stores integer data
    struct node *next;     					// Stores address of next node
};
struct node *head = NULL;  				// Global pointer pointing to first node

// Function to create a new node
struct node* createNode(int value)
{
    struct node *newnode;                              		// Declare pointer
    newnode = (struct node*)malloc(sizeof(struct node));  // Allocate memory
    newnode->data = value;                             		// Assign value
    newnode->next = NULL;                              		// Set next as NULL
    return newnode;                                    		// Return node address
}

// Function to insert at beginning
void insertBeginning(int value)
{
    struct node *newnode = createNode(value); 		// Create new node
    newnode->next = head;                     			// Connect new node to old head
    head = newnode;                           			// Update head pointer
}

// Function to insert at end
void insertEnd(int value)
{
    struct node *newnode = createNode(value); 		// Create new node
    struct node *temp = head;                 			// Temporary pointer

if(head == NULL)                          			// Check if list is empty
    {
        head = newnode;                       			// Make new node as head
        return;                               				// Exit function
    }

    while(temp->next != NULL)                 		// Traverse to last node
        temp = temp->next;                    			// Move pointer

    temp->next = newnode;                     			// Attach new node at end
}

// Function to insert in between
void insertBetween(int key, int value)
{
    struct node *temp = head;                 			// Temporary pointer
    struct node *newnode = createNode(value); 		// Create new node

    while(temp != NULL && temp->data != key)  	// Search for key
        temp = temp->next;                    			// Move pointer

    if(temp == NULL)                          			// If key not found
    {
        printf("Key not found!\n");           
        return;
    }

    newnode->next = temp->next;               		// Link new node
    temp->next = newnode;                     			// Insert node
}

// Function to delete at beginning
void deleteBeginning()
{
    struct node *temp;                        			// Temporary pointer

    if(head == NULL)                          			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    temp = head;                              			// Store head
    head = head->next;                        			// Move head
    free(temp);                               			// Free memory
}

// Function to delete at end
void deleteEnd()
{
    struct node *temp = head;                 			// Temporary pointer
    struct node *prev = NULL;                 			// Previous pointer

    if(head == NULL)                          			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)                    			// If only one node
    {
        free(head);                           			// Free node
        head = NULL;                          			// Set head NULL
        return;
    }

    while(temp->next != NULL)                 		// Traverse to last
    {
        prev = temp;                          			// Store previous node
        temp = temp->next;                    			// Move pointer
    }

    prev->next = NULL;                        			// Break link
    free(temp);                               			// Free last node
}

// Function to delete intermediate node
void deleteBetween(int key)
{
    struct node *temp = head;                 			// Temporary pointer
    struct node *prev = NULL;                 			// Previous pointer

    if(head == NULL)                          			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    if(head->data == key)                     			// If first node matches
    {
        head = head->next;                    			// Move head
        free(temp);                           			// Free node
        return;
    }

    while(temp != NULL && temp->data != key)  	// Search node
    {
        prev = temp;                          			// Store previous
        temp = temp->next;                    			// Move pointer
    }

    if(temp == NULL)                          			// If not found
    {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;                  			// Skip node
    free(temp);                               			// Free memory
}

// Function to traverse list
void display()
{
    struct node *temp = head;                 			// Temporary pointer

    if(head == NULL)                          			// If list empty
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)                       			// Traverse nodes
    {
        printf("%d -> ", temp->data);         			// Print data
        temp = temp->next;                    			// Move pointer
    }

    printf("NULL\n");                         			// End of list
}

// Main function
int main()
{
    int choice, value, key;                   			// Variable declaration

    do                                  				// Infinite loop
    {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Between\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete in Between\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");        			// Ask choice
        scanf("%d", &choice);                 			// Read choice

        switch(choice)                        			// Switch statement
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
                printf("Enter key value: ");
                scanf("%d", &key);
                printf("Enter new value: ");
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
                exit(0);                      					// Terminate program

            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 8);                       				// Loop until exit

    return 0;                                 					// End program
}
