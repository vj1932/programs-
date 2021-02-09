#include<iostream>
using namespace std;
int main(){

int i,n,s=0;
cout<<"Enter  Number";
cin>>n;
if(n<0){
    cout<<"Enter positive  Number";
}
else{
    for(i=0;i<=n;i++){
        s = i+s;
    }
cout<<"output is:"<<s<<endl;
}

return 0;
}
