#include<iostream>
using namespace std;
int main(){
int a,n,i,s;
cout<<"Enter Number:";
cin>>n;
a=n;
while(n){
    s=n%10;
    i=i*10+s;
    cout<<s;
    n=n/10;
}
cout<<endl;
if(a==i){
        cout<<"No is pelindrom"<<endl;

    }
    else{
        cout<<"No Is Not Pelindrom"<<endl;
    }
return 0;
}
