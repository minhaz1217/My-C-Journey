#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;



class disjoint_set{
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    bool isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }

    void unionSet(int x, int y){
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
    disjoint_set dj(5);
    msg("CHECK 2,3", dj.isSameSet(2,3));
    dj.unionSet(2,3);
    msg("CHECK 2,3", dj.isSameSet(2,3));

    return 0;
}
