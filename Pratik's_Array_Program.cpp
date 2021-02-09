#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void maxval(){
   int  temp = a[0];
        for(i=0;i<s;i++)
        {
            if(a[i] > temp){
                temp  = a[i];
            }
        }
    a[sizearray + 6];
    a[sizearray] = temp;
    cout<<"Max Value:"<<temp<<endl;

}
void minval(){
    int temp;
    for(i=0;i<s;i++)
        {
            if(a[i] < temp){
                temp  = a[i];
            }
        }
    cout<<"Min Value:"<<temp<<endl;

}

void average(){
    int temp = 0,i;
        for(i=0;i<s;i++)
        {
            temp  = a[i] + temp;
        }
        temp = temp / s;
        cout<<"Average Value:"<<temp<<endl;
}

int random(){
   return (rand()% (100 - 10 + 1));
}
int main(){

    int n,i = 0,s,sizearray = 10;

    srand(time(NULL));
    int a[sizearray];
    int temp = a[i];
    while(n!=4)
    {
    cout<<"Press 1 For :Create array Manually:\n";
    cout<<"Press 2 For :Random Generate Array:\n";
    cout<<"Press 3 For :Display array:\n";
    cout<<"Press 4 For : Exit:\n";
    cin>>n;
    switch (n)
    {
    case 1:
        cout<<"\nEnter Size:\n";
        cin>>s;
        sizearray = s;
        cout<<"\nEnter Array Value:\n";
        for(i=0;i<s;i++)
        {
            cin>>a[i];
        }
        break;
    case 2:
        cout<<"\nEnter Size:\n";
        cin>>s;
        sizearray = s;
        for(i=0;i<s;i++)
        {
            a[i] = random();
            cout<<"Value Is:\n"<<a[i]<<"\n";
        }
        break;
    case 3:
        minval();
        maxval();
        average();

        break;

    case 4:
        cout<<"Tata BYBY:\n";
        exit(0);
    default:
        cout<<"\nIn Valid Expression!!!!\n";
    }
    }
}
