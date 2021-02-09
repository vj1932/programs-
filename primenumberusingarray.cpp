#include<iostream>
using namespace std;
void fun(int a[n],int n);
int main()
{
    int i,n;
    cout<<"Enter Size";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    fun(a[n],n);
    return 0;
}
void fun(int a[n],int n)
{
    int i,sum=0;
    for(i=1;i<=n;i++)
    {
        if(a[i] % i == 0)
        {
            sum++;
        }
    }
    if(sum==2)
    {
        cout<<"No is Prime"<<n<<endl;
    }
    else
    {
        cout<<"No Is not prime"<<n<<endl;
    }
}
