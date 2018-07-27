#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

class disjoint{
    vector<int>p,rt;
public:
    disjoint(int n){
        p.assign(n,0);
        rt.assign(n, -1);
        for(int i=0;i<n;i++){
            p[i] = i;
        }

    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }
        p[x] = findSet(p[x]);
        return p[x];
    }

    int isSameSet(int x, int y){
        return findSet(x) == findSet(y);
    }
    int unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){
                    rt[b]++;
                }
            }
        }
    }
};

int main(){
    int n,i,a;
    cin >> n;
    disjoint dj(n+1);
    for(i=1;i<=n;i++){
        cin >> a;
        if(a != -1){
            dj.unionSet(i,a);
        }
    }
    for(i=1;i<=n;i++){
        msg(i, dj.findSet(i));
    }

    return 0;
}
