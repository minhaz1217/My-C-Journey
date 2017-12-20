#include<bits/stdc++.h>
using namespace std;
int gg;
int gcd(int a, int b){
    //cout << a << " : " << b << endl;
    if(a==b){
        return a;
    }else if(a== 0){
        return b;
    }else if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
int main(){

    int bb = gcd(80,50);
    cout << bb << endl;
}
