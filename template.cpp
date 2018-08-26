#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    for(int i=0;i<100;i++){
        cc( ((rand()%100) < 25) )
    }
    return 0;
}

/*
cout << "Case "<< caseCounter++ << ": " << endl;
for(int pq=0;pq<MX;pq++){
    for(int PQ=0;PQ<MX;PQ++){
        printf("%2d ", mat[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
/*
Minhazul Hayat Khan
EWU
Problem Name:
Problem Link:
Date : 9 / February / 2018
Comment:


//-----Disjoint Set Union ------


class disjoint_set{
private:
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n, 0);
        rt.assign(n, 0);
        for(int i=0;i<n;i++){
            p[i] = i ;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            return p[x] = findSet(p[x]);
        }
    }
    bool isSameSet(int x,int y){
        return findSet(x) == findSet(y);
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
//-----------Disjoint END-----------


*/
