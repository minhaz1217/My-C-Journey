#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int visited[10000];
int main(){
    int x,n,u,counter = 0,i,v;
    cin >> x >> n;
    queue<int> q;
    for(i=0;i<=n*10;i++){
        visited[i] = 0;
    }
    q.push(0);
    while(!q.empty()){
        u = q.front();
        q.pop();
        q.push(u+1);
        if(u == x){
            counter++;
        }else if(u>x){
            continue;
        }
        for(i=u;u + pow(i,n) <= x;i++){
            v = u + pow(i,n);
            if(!visited[v]){

            q.push(u + pow(i,n));
                visited[v] = 1;
            }

        }
       // q.push(u+1);
    }
    cout << counter << endl;

    return 0;
}
