#include<iostream>
using namespace std;
void area(double PI,int r){
    double s;
    s=PI*r*r;
    cout<<s;
}
int main(){

    int PI,r;
    cout<<"Enter Number";
    cin>>r;
    area(3.14 , r);
    return 0;
}
