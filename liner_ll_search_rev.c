#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to traverse the list
void traverse() {
    struct Node* temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to count nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to search for a value
void search(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", key);
}

// Function to insert at the end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
        printf("Inserted %d as head node.\n", value);
        return;
    }

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

// Function to delete a node with a specific value
void deleteNode(int key) {
    struct Node *temp = head, *prev = NULL;

    if (temp && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Node with value %d deleted from head.\n", key);
        return;
    }

    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Function to reverse the list
void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
}

// Main function with switch-case
int main() {
    int choice, value;

    do {
        printf("\n--- Linked List Menu ---\n");
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
                reverseList();
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
    getchar(); // catches newline
    getchar(); // wait for ENTER
    return 0;
}
