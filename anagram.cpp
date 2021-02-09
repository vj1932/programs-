#include <iostream>
#include<bits/stdc++.h>
#include <string.h>
using namespace std;
int main()
{
    int i,j,flg=0;
    int s,b;
    int n=0;
    string str;
    string str1;
    string s1;
    cout<<"Enter String"<<endl;
    getline(cin, str);
    cout<<"Enter second string"<<endl;
    getline(cin, str1);
    s=str.length();
    b=str1.length();
    sort(str.begin(), str.end());
    sort(str1.begin(), str1.end());
    cout<<"str1:"<<str1<<"  "<<"str:"<<str<<endl;
    if(s!=b){
        cout<<"not anagram";
    }
    else{

        for(i=0;i<s;i++){
            if(str[i]==str1[i]){
                n++;
            }
        }
    }
    if(s==n){
        cout<<"is anagram";
    }
    else{
        cout<<"not anagram";
    }
    return 0;
}
