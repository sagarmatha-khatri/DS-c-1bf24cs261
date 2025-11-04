#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 3
int queue [N];
int front=-1;
int rear=-1;



void enque(int x)
{
   if (rear==N-1){
        printf("STACKOVERFLOW111 \n");
   }else if(front==-1 && rear==-1)
   {
       front++;rear++;
       queue[rear]=x;
   }else
   {
       rear++;
       queue[rear]=x;
   }
}



void deque()
{
    if(front==-1 && rear==-1)
    {
        printf("empty que");
    }else if (rear==front)
    {
        printf("the deleted element is %d\n",queue[front]);
        front=rear=-1;
    }else
    {
        int x=queue[front];
        front++;
        printf("the deleted element is %d\n",x);
    }
}



void display ()
{
    if (front==-1&&rear==-1)
    {
        printf("stack is empty\n");
    }else
    {
        printf("stack elements are: \n");
        for (int i= front; i<=rear;i++){
            printf("%d\n", queue[i]);
        }
    }
}


void ooru()
{
    if (front==-1 && rear==-1){
        printf("UNDERFlOW");
    }else if(rear>=N)
    {
        printf("OVERFLOW");
    }else
    {
        printf("elements are present!!!!");
    }
}


int main()
{
    int choice,x;
    while (1){
        printf ("\n queue\n");
        printf ("1.Insert \n");
        printf ("2.Delete \n");
        printf ("3.Display \n");
        printf ("4.exit\n");
        printf ("5.Empty\n");
        printf ("6.Check OVERFLOW or UNDERFLOW ");
        printf ("\n enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the element you want:");
            scanf("%d",&x);
            enque(x);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting the code bye bye\n");
            return 0;
        case 5:
            display();
            break;
        case 6:
            ooru();
            break;
        default:
            printf ("invalid choice!!!\n");
            break;
        }
    }
    return 0;
}