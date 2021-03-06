#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct queue{
    int f;
    int r;
    int size;
    int *Q;

};

void create(struct queue *q1){

    printf("Enter Size:");
    scanf("%d",&q1->size);
    q1->Q =(int*)malloc(q1->size*sizeof(int));
    q1->r = 0;
    q1->f = 0;

}
void enqueue(struct queue *q1,int x){

    if((q1->r+1)%(q1->size) == q1->f){
        printf("Queue Is Full");
    }
    else{
        q1->r = (q1->r+1)%q1->size;
        q1->Q[q1->r] = x;
    }

}
void display(struct queue q1){
    int front = q1.f,rear = q1.r;
    if(q1.f == -1){
        printf("Queue Is Empty:\n");
        return;
    }
    if(front<=rear)
    {
        while(front <= rear)
        {
            printf("%d ",q1.Q[front]);
            front++;
        }
    }
    else
    {
        while(front <= MAX-1)
        {
            printf("%d ",q1.Q[front]);
            front++;
        }
        front = 0;
        while(front <= rear)
         {
            printf("%d ",q1.Q[front]);
            front++;
        }
    }


}

void dequeue(struct queue *q1){

    int x=-1;
    if(q1->r == q1->f){
        printf("Queue is Empty:");
    }
    else{
        q1->f = (q1->f+1)%(q1->size);
        x = q1->Q[q1->f];
    }
    printf("Removed Element Is:%d\n",x);
}
void main(){


        struct queue q1;
        int n = 0, x = 0;
        create(&q1);

         while(n != 4)
        {
            printf("\nEnter Value Between 1 to 4:\n");
            printf("1 For Insert:\n");
            printf("2 For Delete:\n");
            printf("3 For View All Element:\n");
            printf("4 For Exit:\n");
            scanf("%d",&n);

            switch(n)
            {
                case 1:
                    printf("Enter Element:");
                    scanf("%d",&x);
                    enqueue(&q1,x);
                    break;
                case 2:
                    dequeue(&q1);
                    break;
                case 3:
                    display(q1);
                    break;
                case 4:
                    exit(0);
                    break;
                default:
                    printf("Enter Valid Number:");
                    break;
            }
        }
}
