#include<stdio.h>
#include<string.h>
struct stack {

    int size;
    int top;
    char *s;
};

void create(struct stack *s1,int n){

    int size = n;
    int top = -1;
    s1->s=(char*)malloc(n *sizeof(char));
}
void push(struct stack *s1,char x){

    if(s1->top >= s1->size-1){
        printf("stack is Full:\n");
        return;
    }
    else{
        s1->top++;
        s1->s[s1->top] = x;
    }

}

void dis(struct stack s1){

    for(int i=s1.top;i>=0;i--){
        printf("%c",s1.s[i]);
    }
}
void pop(struct stack *s1){

    if(s1->top == -1){
        printf("stack is underflow:");
    }
    else{
        s1->s[s1->top--];
    }

}
void main()
{

    struct stack s1;
    int n;
    printf("size:");
    scanf("%d",&n);
    char a[n];
    printf("Enter String:\n");
    scanf("%s",&a);
    create(&s1,n);

    for(int i = 0; i < n; i++){
        if(a[i] == '('){
            push(&s1,a[i]);
        }
        else if(a[i] == ')')
        {
            if(s1.top == -1){
                printf("Not Maching");
                return;
            }
            else{
                 pop(&s1);
            }

        }
    }

    if(s1.top == -1){
        printf("Not Maching");
    }
    else{
        printf("maching");
    }


}
