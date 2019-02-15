#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MX 10000040
//#define MX 1000004000
//1000000000
bool mark[MX];
vector<int>vec;
void sieve(){
    int root = sqrt(MX) + 1;
    for(int i=0;i<MX;i++){
        mark[i] = 1;
    }
    for(int i=2;i<=root;i++){
        if(mark[i] == 1){
            for(int j=i;i*j<MX;j++){
                mark[i*j] = 0;
            }
        }
    }
    for(int i=2;i<MX;i++){
        if(mark[i]){
            vec.push_back(i);
        }
    }
}

int main(){
    sieve();
     int sum,n,counter,pos;
    sum = 0;
    //cc(vec.size())
    while(cin >> n){
            if(n ==0){
                break;
            }
            vector<bool>mm(n+2);
        //pos = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
        //cc(pos)
        counter = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i] > n){
                break;
            }
            if(__gcd(n,vec[i]) == 1){
                counter++;
                for(int j=vec[i];vec[i]*j<=n;j++){
                    if( __gcd(vec[i]*j, n) == 1 ){
                        counter++;
                    }
                }
            }
        }
        cout << counter << endl;
    }

    return 0;
}
