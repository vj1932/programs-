#include<iostream>
using namespace std;
int main(){
int s=0,i,n;
cout<<"Enter Number"<<endl;
cin>>n;
for(i=1;i<n;i++){
    if(n%i==0){
        s=s+i;
    }
}
if(n==s){
    cout<<"Number Is perfect";
}
else{
    cout<<"Number Is Not Perfect";
}
return 0;
}
