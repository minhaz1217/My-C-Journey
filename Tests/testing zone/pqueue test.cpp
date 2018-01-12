#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    priority_queue<int> pq;
    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(6);
    pq.push(1);
    while(!pq.empty()){
        cout << pq.top()    << endl;
        pq.pop();
    }



    return 0;
}
