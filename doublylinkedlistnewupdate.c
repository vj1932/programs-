#include<stdio.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
}*first,*last;
int create(int n)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = n;
    p->next = NULL;
    p->prev = NULL;
    first = p;
    return p;
}
void add_first(int n)
{
        struct node *p;
        p = (struct node*)malloc(sizeof(struct node));
        p->data = n;
        if(first == NULL)
        {
            p = create(n);
            return;
        }
        else
        {
            p->prev = NULL;
            p->next = first;
            first->prev = p;
            first = p;
        }
}
int listLength(){
    struct node *p = first;
    if(first == NULL)
    {
        return 0;
    }
    else
    {   int count = 0;
        while(p != NULL)
        {
            count++;
            p = p->next;
        }
       return count;
    }
}
void insert_index(int n,int index)
{
    struct node *p;
    struct node *temp = first;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = n;
    if(index > listLength())
    {
        printf("Not Valid:\n");
        return;
    }
    if(first == NULL)
    {
        create(n);
        return;
    }
    else
    {
        for(int i=1;i<index;i++)
        {
            temp = temp->next;
        }
        ((temp->prev)->next) = p;
        p->prev = temp->prev;
        temp->prev = p;
        p->next = temp;
    }
}
void add_last(int val)
{
    struct node *p = first;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if(first == NULL)
    {
        add_first(val);
        return;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
        last = temp;
    }
}
void display()
{
    struct node *p = first;
    if(first == NULL)
    {
        printf("Linked List Empty:\n");
        return 0;
    }
    else
    {
        while(p->next != NULL)
        {
                printf("%d ",p->data);
                p = p->next;
        }
       printf("%d",p->data);
    }
}
void delete_first()
{
    struct node *p;
    if(first == NULL)
    {
        printf("Linked List Empty:\n");
        return 0;
    }
    else{
       first = first->next;
    }

}
void delete_index(int index)
{
    struct node *p = first;
    if(first == NULL || index <= 0 || index > listLength())
    {
        printf("Not Valid\n");
        return;
    }
    if(index == 1){
        delete_first();
        return;
    } else if(index == listLength()){
        last = last->prev;
        free(last->next);
        last->next = NULL;
        return;
    }
       for(int i = 1;i<index;i++)
        {
                p = p->next;
        }
       (p->prev)->next = p->next;
       (p->next)->prev = p->prev;
       free(p);
}

int search()
{
    int val = 0,temp = 0,index = 0;
    printf("Enter Element:\n");
    scanf("%d",&val);

    if(first == NULL)
    {
        printf("Not Valid\n");
        return;
    }
    struct node *p = first;

    while(p!=NULL)
    {
         index++;
        if(p->data == val)
        {
            temp++;
            break;
        }else{
            p = p->next;

        }

    }
    if(temp == 1)
    {
        printf("Found At:%d\n",index);
    }
    else{
        printf("Not Found:\n");
    }
}


int main()
{
    int n,val1 = 0 ,choice,index = 0,val2 = 0,count = 0,val3 = 0,index1 = 0;
    while(n!=9)
    {
        printf("\n1 for add node:");
        printf("\n2 for add at first position: ");
        printf("\n3 for Display:");
        printf("\n4 for Delete from first:");
        printf("\n5 for Delete At specific index:");
        printf("\n6 for Search:");
        printf("\n7 for Count Nodes:");
        printf("\n8 for Insert At Specific Index:");
        printf("\n9 for exit:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter  Value:\n");
                scanf("%d",&val1);
                add_last(val1);
                break;
            case 2:
                printf("Enter Value:\n");
                scanf("%d",&val2);
                add_first(val2);
                break;
            case 3:
                display();
                break;
            case 4:
                delete_first();
                break;
            case 5:
                printf("Enter Index:\n");
                scanf("%d",&index);
                delete_index(index);
                break;
            case 6:
                search();
                break;
            case 7:
                count = listLength();
                printf("No of nodes is:%d",count);
                break;
            case 8:
                printf("Enter Index:\n");
                scanf("%d",&index1);
                printf("Enter Value:\n");
                scanf("%d",&val3);
                insert_index(val3,index1);
                break;
            case 9:
                printf("BY BY\n");
                exit(0);
                break;
            default:
                printf("Enter Valid Number:\n");
                break;
        }
    }
}

