#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;

int count = 0;

void main()
{
    create();
    int no, ch, e;
     while (ch!=5)
    {
        printf("\n1 For Enque");
        printf("\n2 For Deque");
        printf("\n3 For Display");
         printf("\n4 For Queue size");
        printf("\n5 For Exit\n");
        scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                printf("Enter data : ");
                scanf("%d", &no);
                enq(no);
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                queuesize();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice, Please enter correct choice  ");
                break;
            }
    }
}
void create()
{
    front = rear = NULL;
}
void queuesize()
{
    printf("\n Queue size : %d", count);
}
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n Queue Is Empty");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

