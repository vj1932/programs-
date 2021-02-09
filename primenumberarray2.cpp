#include<iostream>
using namespace std;
int main()
{
    int i,n,sum=0,j;
    cout<<"Enter Size:";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        sum = 0;
        for(j=1;j<=a[i];j++){
            if(a[i] % j == 0){
                sum++;
            }
        }
        if(sum == 2){
            cout<<a[i]<<" Is Prime"<<endl;
        }else{
            cout<<a[i]<<" Is Not Prime"<<endl;
        }
    }

    return 0;
}
