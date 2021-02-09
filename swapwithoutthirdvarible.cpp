#include<iostream>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
b=b+a;
a=b-a;
b=b-a;
cout<<"a:"<<a<<"b:"<<b;
return 0;
}
