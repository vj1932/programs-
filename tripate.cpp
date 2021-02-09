#include<iostream>
using namespace std;
int main(){
float fact=1,i,n,c=1,j=1;
float s=0;
cout<<"Enter Number"<<endl;
cin>>n;
for(i=1;i<=n;i++){
    fact=fact*i;
    s+=i/fact;
}

cout<<s;
return 0;

}
