/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://onlinejudge.org/external/106/10650.pdf
Date : 27 / October / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define SIEVE 32004
bool mark[SIEVE];
vector<int>prime;
void sieve(){
    int root = sqrt(SIEVE)+1;
    for(int i=2;i<root;i++){
        if(mark[i] == 0){
            for(int j=i;i*j<SIEVE;j++){
                mark[i*j] = 1;
            }
        }
    }
    for(int i=2;i<SIEVE;i++){
        if(mark[i] == 0){
            prime.push_back(i);
        }
    }
}
int main(){
    sieve();
    long long int l,r,dist;
    vector<vector<int> >vec;
    for(int i=0;i<prime.size()-2;i++){
        if(prime[i+2] - prime[i+1] == prime[i+1] - prime[i]){
            dist = prime[i+2] - prime[i+1];
            vector<int>myVec;
            myVec.push_back(prime[i]);
            for(int j=i+1;j<prime.size()-1;j++){
                if(prime[j] - prime[j-1] == dist){
                    myVec.push_back(prime[j]);
                    i=j-1;
                }else{
                    break;
                }
            }
            vec.push_back(myVec);
//            msg2("DIST", dist, myVec.size());
        }
    }
//        sort(vec.begin(), vec.end());
//        cout << vec.size() << endl;
    while(cin >> l >> r){
        if(l ==0 && r == 0){
            break;
        }
        if(r < l){
            swap(l,r);
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i][0] >= l && vec[i][ vec[i].size()-1 ] <=r){
                for(int j=0;j<vec[i].size();j++){
                    if(j>0){
                        cout << " ";
                    }
                    cout << vec[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
