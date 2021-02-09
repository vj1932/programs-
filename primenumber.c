#include<iostream>
using namespace std;
int main(){
int i,a;
cout<<"Enter Number"<<endl;
cin>>a;
for(i=2;i< = a/2 ;i++){
    if(a%2 ==0){
        cout<<"No is Prime";
    }
    else{
        cout<<"No is Not Prime";
    }
}
return 0;
}
