#include <stdio.h>
#include <stdlib.h>

// Typedef Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Traverse list
void traverse() {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Count nodes
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search element
void search(int key) {
    Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found.\n", key);
}

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end.\n", value);
}

// Insert at position (smart call)
void insertAtPosition(int value, int position) {
    int count = countNodes();
    int i;
    if (position <= 1) {
        insertAtBeginning(value);
    } else if (position > count) {
        insertAtEnd(value);
    } else {
        Node* newNode = createNode(value);
        Node* temp = head;
        for (i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", value, position);
    }
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    if (temp->next == NULL) {
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        printf("Deleted %d from end.\n", temp->data);
        temp->prev->next = NULL;
        free(temp);
    }
}

// Delete from position (smart call)
void deleteFromPosition(int position) {
    int count = countNodes();
    int i;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position <= 1) {
        deleteFromBeginning();
    } else if (position >= count) {
        deleteFromEnd();
    } else {
        Node* temp = head;
        for (i = 1; i < position; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("Deleted %d from position %d.\n", temp->data, position);
        free(temp);
    }
}

// Reverse the list
void reverseList() {
    Node* temp = NULL;
    Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    printf("List reversed.\n");
}

// Main menu
int main() {
    int choice, value, position,i;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Traverse\n");
        printf("2. Count Nodes\n");
        printf("3. Search\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Position\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 6:
                reverseList();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

