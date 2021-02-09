#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first = NULL;


int index_specific(struct node *p,int index ,int x)
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    if(index < 0 || index > nodes(first))
    {
        return;
    }
    else
    {
        if(index == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            p = first;
            for(int i=0;i<index-1;i++)
            {
                p = p->next;
            }
                t->next = p->next;
                p->next = t;
        }
    }
}
void first_node(int n)
{
        struct node *t,*last;
        first = (struct node*)malloc(sizeof(struct node));
        first->data = n;
        first->next = NULL;

}

void add_node(int n)
{

    struct node *t,*last;
    if(first == NULL){
        first = (struct node*)malloc(sizeof(struct node));
        first->data = n;
        first->next = NULL;
    }
    else
    {
        struct node *temp=first;
        t = (struct node*)malloc(sizeof(struct node));
        t->data = n;
        t->next = NULL;
            while(temp->next!=NULL){
                    temp = temp->next;
            }
             temp->next = t;
    }
}

void display(struct node *p)
{
    if(first->data == NULL){
        printf("Linked List Empty:\n");
        return;
    }
    else
    {
        int x = 0;
        while(p!=NULL){
            printf("%d ",p->data);
            p = p->next;
        }
    }
}
int nodes(struct node *p)
{
    int x = 0;
    while(p!=NULL){
        p = p->next;
        x++;
    }
    return x;
}

void sum(struct node *p){
    int x = 0;
    while(p!=NULL){
        x+=p->data;
        p = p->next;
    }
    printf("\nSum Is:%d",x);
}

void max(struct node *p){

    int max=0;
    max = p->data;
    while(p!=NULL)
    {
        if(max < p->data)
        {
            max=p->data;
        }
        p = p->next;
    }
    printf("\nMax Value Is:%d",max);

}

void min(struct node *p){

    int max=0;
    max = p->data;
    while(p!=NULL)
    {
        if(max > p->data)
        {
            max=p->data;
        }
        p = p->next;
    }
    printf("\nMin Value Is:%d",max);

}

void search(struct node *p,int x)
{
    while(p!=NULL)
    {
        if(x == p->data)
        {
            printf("Element Are Found:%d\n",x);
            break;
        }
        else{
            printf("Element Are Not Found:%d\n",x);
            break;
        }
        p = p->next;
    }
}
int main()
{
    int x = 0,find,index,val,n,val1,val2;
    int arr;
    while(n!=10)
    {
        printf("\n1 For Create:\n");
        printf("2 For Insert at specific index:\n");
        printf("3 For Total sum :\n");
        printf("4 For Min Val :\n");
        printf("5 For Max Val :\n");
        printf("6 For find value :\n");
        printf("7 For Display:\n");
        printf("8 For Total Number Of Node:\n");
        printf("9 Add Nodes:\n");
        printf("10 For Exit:\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                printf("Enter Value:\n");
                scanf("%d",&val1);
                first_node(val1);
                break;
            case 2:
                printf("Enter Index:\n");
                scanf("%d",&index);
                printf("Enter Value:\n");
                scanf("%d",&val);
                index_specific(first,index,val);
                break;
            case 3:
                sum(first);
                break;
            case 4:
                min(first);
                break;
            case 5:
                max(first);
                break;
            case 6:
                printf("Enter Number TO find:");
                scanf("%d",&find);
                search(first,find);
                break;
            case 7:
                display(first);
                break;
            case 8:
                x = nodes(first);
                printf("\nTotal Number Of Linked List:%d",x);
                break;
            case 9:
                printf("Enter Value:");
                scanf("%d",&val2);
                add_node(val2);
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("\nEnter Valid Number:!!!!");
            }
    }
}
