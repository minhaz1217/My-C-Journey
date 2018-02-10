#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    priority_queue<int, vector<int> ,greater<int> > q_asc;
    priority_queue<int> q_normal;
    int n[] = {1,8,5,6,3,4,0,9,7,2};


    cout << "Normal QUEUE" << endl;
    for( int ii = 0; ii < sizeof(n)/sizeof(n[0]);ii++ ){
        q_normal.push(n[ii]);
    }
    while(!q_normal.empty()){
        cout << q_normal.top() << endl;
        q_normal.pop();
    }
    cout << "Reverse Priority queue" << endl;
    for( int ii = 0; ii < sizeof(n)/sizeof(n[0]);ii++ ){
        q_asc.push(n[ii]);
    }
    while(!q_asc.empty()){
        cout << q_asc.top() << endl;
        q_asc.pop();
    }
    return 0;
}
