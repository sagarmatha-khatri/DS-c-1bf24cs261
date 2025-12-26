#include <stdio.h>
#include <stdlib.h>

/* Node definition */
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

/* Global pointers */
struct node *head = NULL;
struct node *tail = NULL;

/* Create doubly linked list */
void creation(int n) {
    struct node *newNode;
    int data, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

/* Insert at beginning */
void insert_at_beginning(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
}

/* Insert at end */
void insert_at_end(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (tail == NULL) {
        head = tail = newNode;
        newNode->prev = NULL;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

/* Delete at front */
void delete_at_front() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

/* Delete at end */
void delete_at_end() {
    struct node *temp;

    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}

/* Delete by value */
void delete_by_value(int value) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp == head) {
        delete_at_front();
    } else if (temp == tail) {
        delete_at_end();
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

/* Display list */
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main menu */
int main() {
    int choice, n, data;

    while (1) {
        printf("\n----- Doubly Linked List Operations -----\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at End\n");
        printf("6. Delete by Value\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            creation(n);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_at_beginning(data);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;

        case 4:
            delete_at_front();
            break;

        case 5:
            delete_at_end();
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            delete_by_value(data);
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
