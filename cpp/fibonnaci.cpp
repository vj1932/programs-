#include<iostream>
using namespace std;
int main(){
    int i,a=0,b=1,n,c;
    cout<<"Enter Number:"<<endl;
    cin>>n;
    cout<<" "<<a<<" "<<b;
    for(i=1;i<=n-2;i++){
        c=a+b;
        cout<<" "<<c;
        a=b;
        b=c;
    }
return 0;
}
