/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 06 / April / 2019
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

deque<long long int >dq,fn;
set<long long int>vec2[105];
set<long long int>::iterator it;;
vector<long long int>vec[105];
vector<long long int >num;
void bd(int n){
//    msg2("HI",n, dq.size())
//    for(int i=0;i<dq.size();i++){
//        //cout << dq[i] << " ";
//    }
//    cout << endl;
    if(n>num.size()){
        return;
    }
    if(n == num.size()){
        fn = dq;
        cc("FOUND")
        return;
    }
    for(int j=0;j<vec[n].size();j++){
        if(dq[dq.size()-1] * vec[n][j] == num[n] ){
            dq.push_back( vec[n][j] );
            bd(n+1);
            if(dq.size()>= num.size()){
                break;
            }
            dq.pop_back();
        }
    }

}
#define SIEVE 10200
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
    msg("SIZE", prime.size())
    long long int tc,n,k,a,b,p,l;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        cin >> a;
        vec2[0].clear();
        for(int i=0;prime[i]<=n;i++){
            if(a%prime[i] == 0){
                vec2[0].insert(prime[i]);
                b = a/ prime[i];
                if( b<=n ){
                    if(mark[b] == 0){
                        vec2[0].insert(b);
                    }
                }
            }
        }
        num.push_back(a);

        for(l=1;l<k;l++){
            cin >> a;
            vec2[l].clear();
            num.push_back(a);
            for(it = vec2[l-1].begin();it!=vec2[l-1].end();it++){
                p = *it;
                if( a%p == 0 ){
                    b = a/p;
                    if( b<=n ){
                        if(mark[b] == 0){
                            vec2[l].insert(b);
                        }
                    }
                }
            }

        }
        for(int i=0;i<k;i++){
            for(it = vec2[i].begin();it!=vec2[i].end();it++){
                vec[i].push_back(*it);
            }
        }
//        cc("STARTING")
//        for(int i=0;i<l;i++){
//            for(int j=0;j<vec[i].size();j++){
//                cout << vec[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cc(num.size())
        for(int i=0;i<vec[0].size();i++){
            dq.push_back(vec[0][i]);
            bd(0);
            if(fn.size() == num.size()+1){
                break;
            }
        }
        vector<long long int>nw;
        for(int i=0;i<fn.size();i++){
            nw.push_back(fn[i]);
        }
        sort(nw.begin(), nw.end());
        for(int i=0;i<fn.size();i++){
            for(int j=0;j<nw.size();j++){
                if(nw[j] == fn[i]){
                    cc(j)
                    //cout << (char)(j+'A');
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
