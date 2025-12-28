#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create list */
void createList(int n) {
    struct Node *newNode, *temp = NULL;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printf("Linked List created successfully.\n");
}

/* Delete at beginning */
void deleteAtBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

/* Delete at end */
void deleteAtEnd() {
    struct Node *temp, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

/* Delete at any position */
void deleteAtAnyPos(int pos) {
    struct Node *temp = head, *prev = NULL;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

/* Display list */
void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("The elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main */
int main() {
    int choice, n, pos;

    while (1) {
        printf("\n---- Singly Linked List Operations ----\n");
        printf("1. Create Linked List\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at Any Position\n");
        printf("4. Delete at End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;

        case 2:
            deleteAtBeginning();
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtAnyPos(pos);
            break;

        case 4:
            deleteAtEnd();
            break;

        case 5:
            displayList();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}