#include <bits/stdc++.h>
#define MAX 100
using namespace std;
struct Empolyee_Details{
    int id;
    char name[MAX];
    int salary;
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
        scanf("%d",&e1[i].salary);
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
        printf("Salary:%d\n",e1[i].salary);
    }
}

void delete_emp(struct Empolyee_Details e1[],int index,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(index == i)
        {
            cout<<"Loop Coming:";
            for(j=i;j<n;j++)
            {
                 e1[j].id = e1[j+1].id;
                 cout<<e1[j].id<<endl;
                 e1[j].name[j] = e1[j+1].name[j];
                 cout<<e1[j].name[j]<<endl;
                 e1[j].salary =  e1[j+1].salary;
                 cout<<e1[j].salary<<endl;
                 (e1[i].name,NULL);
                 (e1[i].id,NULL);
                 (e1[i].salary,NULL);
            }
        }
    }
    printf("Element is deleted:");
}

int main(){
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
            default:
                cout<<"Enter valid number:"<<endl;
        }

    }
    return 0;

}

