#include<iostream>
using namespace std;
int main(){
int i,j;
double fact=1;
cout<<"Enter Number:";
cin>>j;
for(i=1;i<=j;i++){
    fact = fact *i;
}
cout<<fact<<endl;
return 0;
}
