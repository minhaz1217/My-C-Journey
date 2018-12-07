#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > >vec;

    cin >> n;
    for(i=1;i<n/2+2;i++){
        if( n% (i+i+1) == i+1  ){
            //msg(i+1,i)
            vec.push(make_pair(i+1,i));
        }
        if(n % i == 0){
            vec.push(make_pair(i,i));
        }
        if(n % (i+i+1)== 0){
            vec.push(make_pair(i+1,i));
        }
    }
    cout << n << ":" << endl;
        pair<int,int> u,last;
    while(!vec.empty()){
        u = vec.top();
        vec.pop();
        if(u == last || (u.first == 1 && u.second==1) || u.first+u.second > n){
            continue;
        }
        printf("%d,%d\n", u.first, u.second);
        last = u;
    }
    return 0;
}
