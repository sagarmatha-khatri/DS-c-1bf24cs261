#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = item;
    }
    else if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = item;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow!!\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("%d removed!!\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        for (int i = front; i <= rear; i = (i + 1) % MAX)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    int value;
    int n;
    while (1)
    {
        printf("CHOOSE:\n 1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.EXIT\n");
        scanf("%d", &value);
        switch (value)
        {
        case 1:
            printf("Enter the value you want to insert\n");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;

        default:
            break;
        }
    }
    return 0;
}