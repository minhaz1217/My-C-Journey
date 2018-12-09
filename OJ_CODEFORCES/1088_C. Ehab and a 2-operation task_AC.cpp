// funny math problem, medium level hard, twist in the problem.
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    int n,a,m,currAdd,prev;
    vector<int>vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    m = vec.size();
    currAdd  = 0;
    prev = 0;
    cout << n+1 << endl;
    for(int i=vec.size()-1;i>=0;i--){
        prev = currAdd;
        currAdd += m - ((vec[i]+currAdd) %m) + i;
        cout << 1 << " "<<i+1 << " " << currAdd - prev << endl;
        //cout << currAdd << endl;
    }
    cout << 2 << " " << n << " " << m << endl;






    return 0;
}
