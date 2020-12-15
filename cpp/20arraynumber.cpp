#include<iostream>
using namespace std;
int main(){
int n;
int avg,i,j,sum=0;
int max=0,min=0;
cout<<"Enter size input:"<<endl;
cin>>n;
int a[n];
for(i=0;i<n;i++){
    cin>>a[i];
}
// sum

for(i=0;i<n;i++){
    sum=a[i]+sum;
}
cout<<"Sum Is:"<<sum<<endl;

//Average
sum = 0;

for(i=0;i<n;i++){
    sum=a[i]+sum;
}
avg=sum/n;
cout<<"Average Is:"<<avg<<endl;


//Max Value
max=a[i];
for(i=0;i<n;i++){
    if(a[i] > max){
        max=a[i];
    }
}
cout<<"Max value is:"<<max<<endl;
//Min Value
min=a[i];
for(i=0;i<n;i++){
    if(a[i] < min){
        min=a[i];
    }
}
cout<<"Min value is:"<<min;
return 0;
}
