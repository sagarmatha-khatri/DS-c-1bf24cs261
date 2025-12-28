#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* STACK OPERATIONS */
struct node* push(struct node* top, int x) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return top;
    }
    p->data = x;
    p->next = top;
    return p;
}

struct node* pop(struct node* top) {
    struct node* temp;

    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }

    temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}

/* QUEUE OPERATIONS */
void enqueue(struct node **front, struct node **rear, int x) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    p->data = x;
    p->next = NULL;

    if (*front == NULL) {
        *front = *rear = p;
    } else {
        (*rear)->next = p;
        *rear = p;
    }

    printf("Enqueued %d\n", x);
}

void dequeue(struct node **front, struct node **rear) {
    struct node *temp;

    if (*front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = *front;
    printf("Dequeued %d\n", temp->data);
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

/* DISPLAY */
void display(struct node *head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL;
    struct node *front = NULL, *rear = NULL;
    int c, x;

    while (1) {
        printf("\nMENU\n");
        printf("1. Stack - Push\n");
        printf("2. Stack - Pop\n");
        printf("3. Queue - Enqueue\n");
        printf("4. Queue - Dequeue\n");
        printf("5. Stack - Display\n");
        printf("6. Queue - Display\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            top = push(top, x);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(&front, &rear, x);
            break;

        case 4:
            dequeue(&front, &rear);
            break;

        case 5:
            printf("Stack: ");
            display(top);
            break;

        case 6:
            printf("Queue: ");
            display(front);
            break;

        case 7:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
