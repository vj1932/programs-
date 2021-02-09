#include<bits/stdc++.h>
#define MAX 10
using namespace std;
struct bank
{
    float bal;
    int pass;
    string name;
    string mob_num;
    string address;
    int acc_no;
}s[MAX];

int acc_match(int acc,int password,int j)
{
    int i,temp = 0;
    for(i=0;i<j;i++)
    {
        if(s[i].acc_no == acc && s[i].pass == password)
        {

                cout<<"Name:"<<s[i].name<<endl;
                cout<<"Balance:"<<s[i].bal<<endl;
                cout<<"Mobile No:"<<s[i].mob_num<<endl;
                cout<<"Address:"<<s[i].address<<endl;
                cout<<"Account Number:"<<s[i].acc_no<<endl;
                temp++;
                break;
        }
    }
    if(temp == 0)
    {
        cout<<"Not Found:"<<endl;
    }
}

int tras_money(int acc,int password,int j)
{
        int i = 0,temp = 0,k = 0,tempbal = 0,checkbal = 0,acc_check = 0;
        int acc2 = 0,boo = 0;
        float bal2 = 0;
            for(i=0;i<=j;i++)
            {
                if(s[i].acc_no == acc && s[i].pass == password)
                {
                        boo = 1;
                        cout<<"Enter Another Account Number:"<<endl;
                        cin>>acc2;
                        break;
                }
            }
            if(boo == 1)
            {
                for(k=0;k<=j;k++)
                {
                    if(s[k].acc_no == acc2)
                    {
                        cout<<"Enter Money To transfer"<<endl;
                        cin>>bal2;
                        acc_check = 1;
                        if(s[i].bal <= bal2)
                        {
                            cout<<"Don't Have Enought Money:"<<endl;
                        }
                        else
                        {
                            s[i].bal = s[i].bal - bal2;
                            s[k].bal = s[k].bal + bal2;
                            if(s[i].bal < 2000)
                            {
                                cout<<"Can't Transfer:"<<endl;
                                s[i].bal = s[i].bal + bal2;
                                s[k].bal = s[k].bal - bal2;
                            }
                            else
                            {
                                cout<<"Transfer Money Successfully"<<endl;
                                cout<<"Your Balance Is:"<<s[i].bal<<endl;
                            }
                        }
                    }
                }

            }
            else
            {
                cout<<"Wrong Details:"<<endl;
            }
    if(acc_check == 0 )
    {
        cout<<"Account not Exist"<<endl;
    }
}

int check_bal(int bal)
{
    int temp = 0;
        if(bal < 2000)
        {
            cout<<"Balance Must Be greter than 2000"<<endl;
            cout<<"Enter Balance:"<<endl;
            cin>>temp;
        }
        else{
            temp = bal;
        }
    return temp;

}
int deposite(int acc,int password,int j)
{
    float money = 0;
    int i = 0,temp = 0;
    for(i = 0;i <= j;i++)
    {
        if(s[i].acc_no == acc && s[i].pass == password)
        {
            cout<<"Enter Money:"<<endl;
            cin>>money;
            temp = 1;
            break;
        }
    }
    if(temp == 0)
    {
        cout<<"Invalid Details:"<<endl;
    }
    else
    {
         if(money < 0)
            {
                cout<<"Can't Deposite:"<<endl;
            }
            else
            {
                s[i].bal = s[i].bal+money;
                cout<<"Money Deposite Succesfully:"<<endl;
                cout<<"Your Balance Is:"<<s[i].bal<<endl;
            }
    }
}

int withdraw(int acc,int password,int j)
{
    float money = 0;
    int i = 0,temp = 0;
    for(i = 0;i <= j;i++)
    {
        if(s[i].acc_no == acc && s[i].pass == password)
        {
            cout<<"Enter Money:"<<endl;
            cin>>money;
            temp = 1;
            break;
        }
    }
        if(temp == 0)
        {
            cout<<"Invalid Details:"<<endl;
        }
        else
        {
            if(money < 0)
            {
                cout<<"Can't Withdraw:"<<endl;
            }
            else
            {
                s[i].bal = s[i].bal-money;
                if(s[i].bal < 2000)
                {
                    cout<<"Can't Withdraw:"<<endl;
                     s[i].bal = s[i].bal+money;
                }
                else{
                cout<<"Money Withdraw Succesfully:"<<endl;
                cout<<"Your Balance Is:"<<s[i].bal<<endl;
                }
            }
        }
    }


/*int change(int acc,int password,int j)
{
    int i = 0,choice = 0;
    for(i = 0;i <= j;i++)
    {
        if(s[i].acc_no == acc && s[i].pass == password)
        {
            cout<<"Which Value Change: "<<endl;
            cout<<
            switch(choice)
            {

            }
        }
    }
}*/

int main()
{
    int choice = 0,i = 0,j = 0,acc = 1001,acc_number,acc_password,temp = 0,acc_check = 0;
    cout<<"**************************************"<<endl<<endl;
    cout<<"Basic Instruction:"<<endl;
    cout<<"Balance Must Be greter than 2000"<<endl;
    cout<<"Password Must Be in Number:"<<endl<<endl;
    cout<<"**************************************"<<endl<<endl;
    while(choice!=7)
    {
        printf("\n1 For New User:\n");
        printf("2 For Display:\n");
        printf("3 For Transfer Money:\n");
        printf("4 For Deposite Money:\n");
        printf("5 For withdraw Money:\n");
        printf("6 For Change(In progress) Don't Run Money:\n");
        printf("7 For Exit:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Details Here:\n");
                printf("Enter Name:\n");
                cin>>s[i].name;
                cout<<"Enter Mobile Number:"<<endl;
                cin>>s[i].mob_num;
                cout<<"Enter Address:"<<endl;
                cin>>s[i].address;
                cout<<"Enter Balance:"<<endl;
                cin>>s[i].bal;
                temp = check_bal(s[i].bal);
                s[i].bal = temp;
                temp = 0;
                cout<<"Enter Password:"<<endl;
                cin>>s[i].pass;
                s[i].acc_no = acc;
                cout<<"Your Account Number Is:"<<endl;
                cout<<acc<<endl;
                acc++;
                i++;
                j++;
                break;

            case 2:
                cout<<"Enter Account Number:"<<endl;
                cin>>acc_number;
                cout<<"Enter Password:"<<endl;
                cin>>acc_password;
                acc_match(acc_number,acc_password,j);
                break;

            case 3:
                cout<<"Enter Account Number:"<<endl;
                cin>>acc_number;
                cout<<"Enter Password:"<<endl;
                cin>>acc_password;
                tras_money(acc_number,acc_password,j);
                acc_number = 0;
                acc_password = 0;
                break;

            case 4:
                cout<<"Enter Account Number:"<<endl;
                cin>>acc_number;
                cout<<"Enter Password:"<<endl;
                cin>>acc_password;
                deposite(acc_number,acc_password,j);
                acc_number = 0;
                acc_password = 0;
                break;

            case 5:
                cout<<"Enter Account Number:"<<endl;
                cin>>acc_number;
                cout<<"Enter Password:"<<endl;
                cin>>acc_password;
                withdraw(acc_number,acc_password,j);
                acc_number = 0;
                acc_password = 0;
                break;
            case 6:
                cout<<"Enter Account Number:"<<endl;
                cin>>acc_number;
                cout<<"Enter Password:"<<endl;
                cin>>acc_password;
                //change(acc_number,acc_password,j);
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}
