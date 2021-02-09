#include<iostream>
using namespace std;
int main(){
    int n,m;
    int i,sum=0,j;
    cout<<"Enter row";
    cin>>n;
    cout<<"Enter Column";
    cin>>m;
    int a[n][m];
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
            }

    }

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i]==a[j]){
                        sum=a[i]+a[j];
                }
            }
        }
        cout<<"sum is"<<sum;

return 0;
}
