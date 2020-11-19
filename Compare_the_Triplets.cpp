#include<iostream>
using namespace std;
int main(){
    int n;

    int i,j,s,d;
    int Alice=0,bob=0;
    cout<<"Enter Number";
    cin>>n;
    int a[n],b[n];
    cout<<"Enter Number For A:";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"Enter Number For B:";
    for(j=0;j<n;j++){
        cin>>b[j];
    }
    for(j=0;j<n;j++){
        //cout<<b[j]<<" "<</n;
    }
    for(i=0;i<n;i++)
    {

            //cout<<"a[i]"<<a[i]<<" "<<"b[j]"<<b[i]<<" ";
            if(a[i] > b[i])
            {
                Alice = Alice + 1;
                //cout<<"Alice"<<Alice<<" ";
            }
             if(a[i] < b[i])
            {
                bob = bob + 1;
                //cout<<"bob"<<bob<<" ";
            }
            if(a[i]==b[i]){
                Alice = Alice;
                bob = bob;
            }

    }
    cout<<Alice<<" "<<bob;
    return 0;
}
