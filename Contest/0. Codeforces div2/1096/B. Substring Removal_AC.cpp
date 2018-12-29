#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,left, right,i,counter;
    string str;
    char c1,c2;

    cin >> n;
    cin >> str;
    c1 =str[0];

    for(i=0;str[i];i++){
        if(str[i]!= c1){
            break;
        }
    }
    left = i;
    c2 = str[str.size()-1];
    for(i=str.size()-1;i>=0;i--){
        if(str[i] != c2){
            break;
        }
    }
    right = str.size() - i-1;
    //msg(left, right)
    counter = 0;
    if(c1 != c2 || left == str.size()){
        if(left == str.size()){
            counter = (left * (left+1)) / 2;
        }else{
            counter = left+right+1;
        }
    }else{
        counter = left+right+1+(left*right);
    }
    cout << counter%998244353   << endl;
    return 0;
}
