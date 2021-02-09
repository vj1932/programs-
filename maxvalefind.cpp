#include<iostream>
using namespace std;
int main(){

    int s,i;
    cout<<"\nEnter Size:\n";
    cin>>s;

    int a[s];
    for(i=0;i<s;i++){
        cin>>a[i];
    }

    int temp = a[i];
    for(i=0;i<s;i++){
        if(a[i] > temp){
            temp = a[i];
        }
    }
    cout<<temp;
}
