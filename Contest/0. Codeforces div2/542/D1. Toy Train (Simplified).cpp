/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 24 / February / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){

    long long int n,m,a,b,endCase,counter,myM;
    vector<long long int> vec[104];

    std::cout << std::fixed;
    cin >> n >> myM;
    for(int i=0;i<myM;i++){
        cin >> a >> b;
        vec[a].push_back(b);
    }
    counter = 0;
    endCase = -1;
    for(int l=1;l<=n;l++){
        m = myM;
        counter = 0;
        endCase = -1;
        priority_queue<long long int>pq[104];
        for(int i=1;i<=n;i++){
            for(int j=0;j<vec[i].size();j++){
                pq[i].push(vec[i][j]);
            }
        }

        for(int i=l;;i++){
            if(i == n+1){
                i=1;
            }
            if(i == endCase){
                break;
            }
            if(pq[i].size()>0){
                if(m == 1){
                    endCase = pq[i].top();
                }
                pq[i].pop();
                //msg2("POP", i, endCase)
                m--;
            }
            counter++;

        }
        if(l>1){
            cout << " ";
        }
        cout << (int)counter;
    }
    cout << endl;


    return 0;
}
