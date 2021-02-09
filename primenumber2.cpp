#include<iostream>
using namespace std;
int main(){
    int j,n,i,s=0,x,flag=0;
    cout<<"Enter end"<<endl;
    cin>>n;

    for(i=1;i<=n;i++){
            s=0;
        for(j=1;j<=i;j++){
            if(i%j==0)
            {
                s++;
            }
        }
         if(s==2)
        {
            cout<<i<<endl;
        }
    }
return 0;
}
