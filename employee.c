#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
struct Empolyee_Details{
    int id;
    char name[MAX];
    float salary;
};

void add(struct Empolyee_Details e1[],int n){
    //struct Empolyee_Details e1[n];
    printf("Enter Details Here:\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter ID Here:\n");
        scanf("%d",&e1[i].id);
        printf("Enter Name Here:");
        scanf("%s",&e1[i].name);
        printf("Enter salary Here:");
        scanf("%f",&e1[i].salary);
    }


}

void display(int n,struct Empolyee_Details e1[])
{
   // struct Empolyee_Details e1[n];
    printf("Display Information:\n");
    for(int i=0;i<n;i++)
    {
        printf("Id:%d\n",e1[i].id);
        printf("Name:%s\n",e1[i].name);
        printf("Salary:%f\n",e1[i].salary);
    }
}

void delete_emp(struct Empolyee_Details e1[],int index,int n)
{
    int i,j;
    for(i=index;i<=n;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            printf("enter first time:\n");
                e1[i].id = e1[j].id;
                printf("%d",e1[i]);
                e1[i].name[i] = e1[j].name[j];
                printf("%s",e1[i].name[i]);
                e1[i].salary = e1[j].salary;
                printf("%f",e1[i].salary);
        }
        printf("enter first time:\n");

    }
    printf("Element is deleted:");
}

void main(){
    int n,choice,glb = 0,id1 = 0;
    printf("Enter How many employees:\n ");
    scanf("%d",&n);
    struct Empolyee_Details e1[n];
    while(choice!=4)
    {
        printf("\n1 For Add Employee:\n");
        printf("2 For Delete Employee:\n");
        printf("3 For Display Employee:\n");
        printf("4 For Exit:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
              add(e1,n);
              break;
            case 2:
                printf("Enter Id:\n");
                scanf("%d",&id1);
                delete_emp(e1,id1,n);
                break;
            case 3:
                display(n,e1);
                break;
            case 4:
                exit(0);
                break;
        }

    }

}

