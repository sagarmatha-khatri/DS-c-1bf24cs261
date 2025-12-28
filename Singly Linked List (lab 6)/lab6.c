#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

/* Create first list */
void createList1(int n) {
    struct Node *newNode, *temp = NULL;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes must be greater than 0\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head1 == NULL)
            head1 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
}

/* Create second list */
void createList2(int n) {
    struct Node *newNode, *temp = NULL;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes must be greater than 0\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head2 == NULL)
            head2 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
}

/* Sort list */
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL) return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

/* Reverse list */
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Concatenate lists */
void concatenate() {
    struct Node *temp;

    if (head1 == NULL) {
        head1 = head2;
        return;
    }

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
}

/* Display list */
void displayList(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n;

    while (1) {
        printf("\n---- Singly Linked List Operations ----\n");
        printf("1. Create First List\n");
        printf("2. Create Second List\n");
        printf("3. Sort Both Lists\n");
        printf("4. Reverse Both Lists\n");
        printf("5. Concatenate Lists\n");
        printf("6. Display Lists\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList1(n);
            break;

        case 2:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList2(n);
            break;

        case 3:
            sortList(head1);
            sortList(head2);
            printf("Lists sorted\n");
            break;

        case 4:
            head1 = reverseList(head1);
            head2 = reverseList(head2);
            printf("Lists reversed\n");
            break;

        case 5:
            concatenate();
            printf("Lists concatenated\n");
            break;

        case 6:
            printf("First List: ");
            displayList(head1);
            printf("Second List: ");
            displayList(head2);
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
