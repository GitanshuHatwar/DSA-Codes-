#include <stdio.h>
#include <stdlib.h>

// Structure for a Doubly Linked List node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node at the end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted %d as head node.\n", value);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", value);
}

// Function to traverse the list
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a value
void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", key);
}

// Function to delete a node with a given value
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Deleting head node
    if (temp->data == key) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Deleted head node with value %d.\n", key);
        return;
    }

    // Traverse to find the node
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    // Adjust links and free memory
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Deleted node with value %d.\n", key);
}

// Function to count nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the list
void reverse() {
    struct Node *temp = NULL, *curr = head;

    if (!head || !head->next) {
        printf("List reversed successfully.\n");
        return;
    }

    // Swap next and prev for all nodes
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // Adjust head
    if (temp != NULL)
        head = temp->prev;

    printf("List reversed successfully.\n");
}

// Main function with menu-driven operations
int main() {
    int choice, value;

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Traverse List\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Search Value\n");
        printf("5. Count Nodes\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 6:
                reverse();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    printf("\n...Program finished with exit code 0\n");
    printf("Press ENTER to exit console.");
    getchar(); // for newline
    getchar(); // wait for ENTER
    return 0;
}
